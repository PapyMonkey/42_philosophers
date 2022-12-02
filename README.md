# 42_philosophers

## Project instructions & grade

"In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes."

### Mandatory part

| Program name | `philo` |
|:--- |:--- |
| **Turn in files** | `Makefile, *.h, *.c, in directory philo/` |
| **Makefile** | `NAME, all, clean, fclean, re` |
| **Arguments** | `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]` |
| **External functions** | `memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock`|
| **Libft authorized** | `No` |
| **Description** | `Philosophers with threads and mutexes` |

Specific rules for the mandatory part are :
- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

### Bonus part

| Program name | `philo_bonus` |
|:--- |:--- |
| **Turn in files** | `Makefile, *.h, *.c, in directory philo_bonus/` |
| **Makefile** | `NAME, all, clean, fclean, re` |
| **Arguments** | `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]` |
| **External functions** | `memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink` |
| **Libft authorized** | `No` |
| **Description** | `Philosophers with processes and semaphores` |

Specific rules for the bonus part are :
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process. But the main process should not be a philosopher.
