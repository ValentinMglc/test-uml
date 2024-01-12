/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Queue
*/

#ifndef SAFEQUEUE_HPP
    #define SAFEQUEUE_HPP

    #include <queue>
    #include <mutex>
    #include <condition_variable>

    template <typename T>
    class Queue {
    public:
        Queue() = default;
        ~Queue() = default;

        // Vérifier si la file d'attente est vide
        bool empty() const noexcept {
            std::lock_guard<std::mutex> lock(mutex);
            return queue.empty();
        }

        // Obtenir la taille de la file d'attente
        size_t size() const noexcept {
            std::lock_guard<std::mutex> lock(mutex);
            return queue.size();
        }

        // Ajouter un élément à la file d'attente
        void push(const T &value) {
            {
                std::lock_guard<std::mutex> lock(mutex);
                queue.push(value);
            }
            condition.notify_one();
        }

        void push(T &&value) {
            {
                std::lock_guard<std::mutex> lock(mutex);
                queue.push(std::move(value));
            }
            condition.notify_one();
        }

        // Extraire un élément de la file d'attente
        T pop() {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock, [this] { return !queue.empty(); });
            T item = std::move(queue.front());
            queue.pop();
            return item;
        }

    private:
        mutable std::mutex mutex;
        std::queue<T> queue;
        std::condition_variable condition;
    };

#endif // QUEUE_HPP
