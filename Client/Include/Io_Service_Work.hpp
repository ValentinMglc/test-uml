/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Io_Service_Work
*/

#ifndef IO_SERVICE_WORK_HPP_
    #define IO_SERVICE_WORK_HPP_

    #include <boost/asio.hpp>
    #include <memory>
    #include <thread>

    class Io_Service_Work {
    public:
        // Constructeur pour initialiser le service IO et le thread de travail
        Io_Service_Work()
            : ioService(std::make_unique<boost::asio::io_service>()),
            ioServiceWork(std::make_unique<boost::asio::io_service::work>(*ioService)),
            ioWorkThread(std::make_unique<std::thread>([this] { ioService->run(); }))
        {}

        // Destructeur pour nettoyer les ressources
        ~Io_Service_Work() {
            ioService->stop();
            if (ioWorkThread && ioWorkThread->joinable()) {
                ioWorkThread->join();
            }
        }

        // Accesseur pour obtenir le service IO
        boost::asio::io_service& getIoService() const {
            return *ioService;
        }

    private:
        std::unique_ptr<boost::asio::io_service> ioService;
        std::unique_ptr<boost::asio::io_service::work> ioServiceWork;
        std::unique_ptr<std::thread> ioWorkThread;
    };

#endif // IO_SERVICE_WORK_HPP_
