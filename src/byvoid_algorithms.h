/*
 * =====================================================================================
 *
 *       Filename:  algorithms.h
 *
 *    Description:  Bling Hashes Native Algorithms Impl
 *
 *        Version:  1.0
 *        Created:  2015/09/11 11时17分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XadillaX <i@2333.moe>
 *   Organization:  Souche.com
 *
 * =====================================================================================
 */
#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

unsigned int SDBMHash(char *str);
unsigned int RSHash(char *str);
unsigned int JSHash(char *str);
unsigned int PJWHash(char *str);
unsigned int ELFHash(char *str);
unsigned int BKDRHash(char *str);
unsigned int DJBHash(char *str);
unsigned int APHash(char *str);

typedef unsigned int (*HashFunc)(char*);

#endif
