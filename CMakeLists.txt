cmake_minimum_required(VERSION 3.19)
project(fdf C)

set(CMAKE_C_STANDARD 99)

add_executable(
        fdf
        sources/main.c
        fdf.h
        sources/get_map.c
        sources/get_next_line.c
        get_next_line.h
        libft/ft_atoi.c
        libft/ft_isdigit.c
        libft/ft_strchr.c
        libft/ft_itoa.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        sources/draw.c sources/utils.c)