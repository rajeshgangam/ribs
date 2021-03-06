/*
    This file is part of RIBS (Robust Infrastructure for Backend Systems).
    RIBS is an infrastructure for building great SaaS applications (but not
    limited to).

    Copyright (C) 2011 Adap.tv, Inc.

    RIBS is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, version 2.1 of the License.

    RIBS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with RIBS.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _LOGGER__H_
#define _LOGGER__H_

#include <stdarg.h>

struct logger
{
    static int create_log_file(const char *logfile);
    static void log(const char *format, ...);
    static void log_at(const char *filename, unsigned int linenum, const char *format, ...);
    static void error(const char *format, ...);
    static void error_at(const char *filename, unsigned int linenum, const char *format, ...);
    static void perror(const char *format, ...);
    static void perror_at(const char *filename, unsigned int linenum, const char *format, ...);
    static void vlog(int fd, const char *format, const char *msg_class, va_list ap);
    static void vlog_at(int fd, const char *filename, unsigned int linenum, const char *format, const char *msg_class, va_list ap);
};

#define LOGGER_WHERE __FILE__, __LINE__
#define LOGGER_INFO(format, ...) logger::log(format, __VA_ARGS__)
#define LOGGER_INFO_AT(format, ...) logger::log_at(LOGGER_WHERE, format, __VA_ARGS__)
#define LOGGER_INFO_STR(x) logger::log("%s", x)
#define LOGGER_INFO_STR_AT(x) logger::log_at(LOGGER_WHERE, "%s", x)
#define LOGGER_ERROR(format, ...) logger::error_at(LOGGER_WHERE, format, __VA_ARGS__)
#define LOGGER_ERROR_EXIT(ec, format, ...) { logger::error_at(LOGGER_WHERE, format, __VA_ARGS__); exit(ec); }
#define LOGGER_ERROR_STR(x) logger::error_at(LOGGER_WHERE, "%s", x)
#define LOGGER_ERROR_STR_EXIT(ec, x) { logger::error_at(LOGGER_WHERE, "%s", x); exit(ec); }
#define LOGGER_PERROR(format, ...) logger::perror_at(LOGGER_WHERE, format, __VA_ARGS__)
#define LOGGER_PERROR_EXIT(ec, format, ...) { logger::perror_at(LOGGER_WHERE, format, __VA_ARGS__); exit(ec); }
#define LOGGER_PERROR_STR(x) logger::perror_at(LOGGER_WHERE, "%s", x)
#define LOGGER_PERROR_STR_EXIT(ec, x) { logger::perror_at(LOGGER_WHERE, "%s", x); exit(ec); }

#endif // _LOGGER__H_
