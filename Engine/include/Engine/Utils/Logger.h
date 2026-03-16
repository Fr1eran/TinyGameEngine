#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>

#define LOG_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define LOG_WARNING(...) SPDLOG_WARN(__VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

#endif // LOGGER_H
