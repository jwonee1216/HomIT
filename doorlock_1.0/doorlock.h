#ifndef DOORLOCK_H_
#define DOORLOCK_H_

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

#define DL_DD_PATH "/dev/doorlock"
#define PASS_PATH "/passwd.txt"
#define PASS_SIZE 25

#define INPUT_KEY 10+48	// key[*]
#define ALTER_KEY 12+48	// key[#]

struct doorlock {
	int fd;

	int lock;
	char pass[PASS_SIZE];
};

typedef struct doorlock doorlock_t;

int init_doorlock(doorlock_t *);

char doorlock_wait_key(doorlock_t *);

char *get_arr_of_keys(doorlock_t *doorlock, char *keys, char end_key);

int is_matched_key(doorlock_t *doorlock, char *keys);

void alter_password(doorlock_t *doorlock, char *keys, int size);

#endif // !DOORLOCK_H_
