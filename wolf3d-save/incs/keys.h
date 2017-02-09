/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:00:42 by skyzie            #+#    #+#             */
/*   Updated: 2017/02/02 16:34:29 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
** Mlx keycode link
*/

# ifdef __APPLE__
#  define KEY_A 0
#  define KEY_B 11
#  define KEY_C 8
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_I 34
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_M 46
#  define KEY_N 45
#  define KEY_O 31
#  define KEY_P 35
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_S 1
#  define KEY_T 17
#  define KEY_U 32
#  define KEY_V 9
#  define KEY_W 13
#  define KEY_X 7
#  define KEY_Y 16
#  define KEY_Z 6
#  define KEY_0 29
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define KEY_6 22
#  define KEY_7 26
#  define KEY_8 28
#  define KEY_9 25
#  define KEY_NUM_0 82
#  define KEY_NUM_1 83
#  define KEY_NUM_2 84
#  define KEY_NUM_3 85
#  define KEY_NUM_4 86
#  define KEY_NUM_5 87
#  define KEY_NUM_6 88
#  define KEY_NUM_7 89
#  define KEY_NUM_8 91
#  define KEY_NUM_9 92
#  define KEY_LEFT 123
#  define KEY_RIGTH 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_PLUS 78
#  define KEY_MOIN 69
#  define KEY_ESC 53
# elif __linux__
#  define KEY_A 0x61
#  define KEY_B 0x62
#  define KEY_C 0x63
#  define KEY_D 0x64
#  define KEY_E 0x65
#  define KEY_F 0x66
#  define KEY_G 0x67
#  define KEY_H 0x68
#  define KEY_I 0x69
#  define KEY_J 0x6a
#  define KEY_K 0x6b
#  define KEY_L 0x6c
#  define KEY_M 0x6d
#  define KEY_N 0x6e
#  define KEY_O 0x6f
#  define KEY_P 0x70
#  define KEY_Q 0x71
#  define KEY_R 0x72
#  define KEY_S 0x73
#  define KEY_T 0x74
#  define KEY_U 0x75
#  define KEY_V 0x76
#  define KEY_W 0x77
#  define KEY_X 0x78
#  define KEY_Y 0x79
#  define KEY_Z 0x7a
#  define KEY_0 0x30
#  define KEY_1 0x31
#  define KEY_2 0x32
#  define KEY_3 0x33
#  define KEY_4 0x34
#  define KEY_5 0x35
#  define KEY_6 0x36
#  define KEY_7 0x37
#  define KEY_8 0x38
#  define KEY_9 0x39
#  define KEY_NUM_1 0x26
#  define KEY_NUM_2 0xe9
#  define KEY_NUM_3 0x22
#  define KEY_NUM_4 0x27
#  define KEY_NUM_5 0x28
#  define KEY_NUM_6 0x2d
#  define KEY_NUM_7 0xe8
#  define KEY_NUM_8 0x5f
#  define KEY_NUM_9 0xe7
#  define KEY_NUM_0 0xe0
#  define KEY_LEFT 0xff51
#  define KEY_RIGTH 0xff53
#  define KEY_UP 0xff52
#  define KEY_DOWN 0xff54
#  define KEY_PLUS 0xffab
#  define KEY_MOIN 0xffad
#  define KEY_ESC 0xff1b
# endif
#endif
