/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD: stable/10/sys/amd64/linux/syscalls.master 293549 2016-01-09 16:48:50Z dchagin 
 */

#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <compat/linux/linux_sysproto.h>
#include <amd64/linux/linux.h>
#include <amd64/linux/linux_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(register_t))

/* The casts are bogus but will do for now. */
struct sysent linux_sysent[] = {
#define	nosys	linux_nosys
	{ AS(read_args), (sy_call_t *)sys_read, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 0 = read */
	{ AS(write_args), (sy_call_t *)sys_write, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 1 = write */
	{ AS(linux_open_args), (sy_call_t *)linux_open, AUE_OPEN_RWTC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 2 = linux_open */
	{ AS(close_args), (sy_call_t *)sys_close, AUE_CLOSE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 3 = close */
	{ AS(linux_newstat_args), (sy_call_t *)linux_newstat, AUE_STAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 4 = linux_newstat */
	{ AS(linux_newfstat_args), (sy_call_t *)linux_newfstat, AUE_FSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 5 = linux_newfstat */
	{ AS(linux_newlstat_args), (sy_call_t *)linux_newlstat, AUE_LSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 6 = linux_newlstat */
	{ AS(poll_args), (sy_call_t *)sys_poll, AUE_POLL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 7 = poll */
	{ AS(linux_lseek_args), (sy_call_t *)linux_lseek, AUE_LSEEK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 8 = linux_lseek */
	{ AS(linux_mmap2_args), (sy_call_t *)linux_mmap2, AUE_MMAP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 9 = linux_mmap2 */
	{ AS(linux_mprotect_args), (sy_call_t *)linux_mprotect, AUE_MPROTECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 10 = linux_mprotect */
	{ AS(munmap_args), (sy_call_t *)sys_munmap, AUE_MUNMAP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 11 = munmap */
	{ AS(linux_brk_args), (sy_call_t *)linux_brk, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 12 = linux_brk */
	{ AS(linux_rt_sigaction_args), (sy_call_t *)linux_rt_sigaction, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 13 = linux_rt_sigaction */
	{ AS(linux_rt_sigprocmask_args), (sy_call_t *)linux_rt_sigprocmask, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 14 = linux_rt_sigprocmask */
	{ AS(linux_rt_sigreturn_args), (sy_call_t *)linux_rt_sigreturn, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 15 = linux_rt_sigreturn */
	{ AS(linux_ioctl_args), (sy_call_t *)linux_ioctl, AUE_IOCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 16 = linux_ioctl */
	{ AS(linux_pread_args), (sy_call_t *)linux_pread, AUE_PREAD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 17 = linux_pread */
	{ AS(linux_pwrite_args), (sy_call_t *)linux_pwrite, AUE_PWRITE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 18 = linux_pwrite */
	{ AS(readv_args), (sy_call_t *)sys_readv, AUE_READV, NULL, 0, 0, 0, SY_THR_STATIC },	/* 19 = readv */
	{ AS(writev_args), (sy_call_t *)sys_writev, AUE_WRITEV, NULL, 0, 0, 0, SY_THR_STATIC },	/* 20 = writev */
	{ AS(linux_access_args), (sy_call_t *)linux_access, AUE_ACCESS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 21 = linux_access */
	{ AS(linux_pipe_args), (sy_call_t *)linux_pipe, AUE_PIPE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 22 = linux_pipe */
	{ AS(linux_select_args), (sy_call_t *)linux_select, AUE_SELECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 23 = linux_select */
	{ 0, (sy_call_t *)sys_sched_yield, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 24 = sched_yield */
	{ AS(linux_mremap_args), (sy_call_t *)linux_mremap, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 25 = linux_mremap */
	{ AS(linux_msync_args), (sy_call_t *)linux_msync, AUE_MSYNC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 26 = linux_msync */
	{ AS(linux_mincore_args), (sy_call_t *)linux_mincore, AUE_MINCORE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 27 = linux_mincore */
	{ AS(madvise_args), (sy_call_t *)sys_madvise, AUE_MADVISE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 28 = madvise */
	{ AS(linux_shmget_args), (sy_call_t *)linux_shmget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 29 = linux_shmget */
	{ AS(linux_shmat_args), (sy_call_t *)linux_shmat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 30 = linux_shmat */
	{ AS(linux_shmctl_args), (sy_call_t *)linux_shmctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 31 = linux_shmctl */
	{ AS(dup_args), (sy_call_t *)sys_dup, AUE_DUP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 32 = dup */
	{ AS(dup2_args), (sy_call_t *)sys_dup2, AUE_DUP2, NULL, 0, 0, 0, SY_THR_STATIC },	/* 33 = dup2 */
	{ 0, (sy_call_t *)linux_pause, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 34 = linux_pause */
	{ AS(linux_nanosleep_args), (sy_call_t *)linux_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 35 = linux_nanosleep */
	{ AS(linux_getitimer_args), (sy_call_t *)linux_getitimer, AUE_GETITIMER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 36 = linux_getitimer */
	{ AS(linux_alarm_args), (sy_call_t *)linux_alarm, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 37 = linux_alarm */
	{ AS(linux_setitimer_args), (sy_call_t *)linux_setitimer, AUE_SETITIMER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 38 = linux_setitimer */
	{ 0, (sy_call_t *)linux_getpid, AUE_GETPID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 39 = linux_getpid */
	{ AS(linux_sendfile_args), (sy_call_t *)linux_sendfile, AUE_SENDFILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 40 = linux_sendfile */
	{ AS(linux_socket_args), (sy_call_t *)linux_socket, AUE_SOCKET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 41 = linux_socket */
	{ AS(linux_connect_args), (sy_call_t *)linux_connect, AUE_CONNECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 42 = linux_connect */
	{ AS(linux_accept_args), (sy_call_t *)linux_accept, AUE_ACCEPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 43 = linux_accept */
	{ AS(linux_sendto_args), (sy_call_t *)linux_sendto, AUE_SENDTO, NULL, 0, 0, 0, SY_THR_STATIC },	/* 44 = linux_sendto */
	{ AS(linux_recvfrom_args), (sy_call_t *)linux_recvfrom, AUE_RECVFROM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 45 = linux_recvfrom */
	{ AS(linux_sendmsg_args), (sy_call_t *)linux_sendmsg, AUE_SENDMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 46 = linux_sendmsg */
	{ AS(linux_recvmsg_args), (sy_call_t *)linux_recvmsg, AUE_RECVMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 47 = linux_recvmsg */
	{ AS(linux_shutdown_args), (sy_call_t *)linux_shutdown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 48 = linux_shutdown */
	{ AS(linux_bind_args), (sy_call_t *)linux_bind, AUE_BIND, NULL, 0, 0, 0, SY_THR_STATIC },	/* 49 = linux_bind */
	{ AS(linux_listen_args), (sy_call_t *)linux_listen, AUE_LISTEN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 50 = linux_listen */
	{ AS(linux_getsockname_args), (sy_call_t *)linux_getsockname, AUE_GETSOCKNAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 51 = linux_getsockname */
	{ AS(linux_getpeername_args), (sy_call_t *)linux_getpeername, AUE_GETPEERNAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 52 = linux_getpeername */
	{ AS(linux_socketpair_args), (sy_call_t *)linux_socketpair, AUE_SOCKETPAIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 53 = linux_socketpair */
	{ AS(linux_setsockopt_args), (sy_call_t *)linux_setsockopt, AUE_SETSOCKOPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 54 = linux_setsockopt */
	{ AS(linux_getsockopt_args), (sy_call_t *)linux_getsockopt, AUE_GETSOCKOPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 55 = linux_getsockopt */
	{ AS(linux_clone_args), (sy_call_t *)linux_clone, AUE_RFORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 56 = linux_clone */
	{ 0, (sy_call_t *)linux_fork, AUE_FORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 57 = linux_fork */
	{ 0, (sy_call_t *)linux_vfork, AUE_VFORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 58 = linux_vfork */
	{ AS(linux_execve_args), (sy_call_t *)linux_execve, AUE_EXECVE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 59 = linux_execve */
	{ AS(linux_exit_args), (sy_call_t *)linux_exit, AUE_EXIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 60 = linux_exit */
	{ AS(linux_wait4_args), (sy_call_t *)linux_wait4, AUE_WAIT4, NULL, 0, 0, 0, SY_THR_STATIC },	/* 61 = linux_wait4 */
	{ AS(linux_kill_args), (sy_call_t *)linux_kill, AUE_KILL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 62 = linux_kill */
	{ AS(linux_newuname_args), (sy_call_t *)linux_newuname, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 63 = linux_newuname */
	{ AS(linux_semget_args), (sy_call_t *)linux_semget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 64 = linux_semget */
	{ AS(linux_semop_args), (sy_call_t *)linux_semop, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 65 = linux_semop */
	{ AS(linux_semctl_args), (sy_call_t *)linux_semctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 66 = linux_semctl */
	{ AS(linux_shmdt_args), (sy_call_t *)linux_shmdt, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 67 = linux_shmdt */
	{ AS(linux_msgget_args), (sy_call_t *)linux_msgget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 68 = linux_msgget */
	{ AS(linux_msgsnd_args), (sy_call_t *)linux_msgsnd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 69 = linux_msgsnd */
	{ AS(linux_msgrcv_args), (sy_call_t *)linux_msgrcv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 70 = linux_msgrcv */
	{ AS(linux_msgctl_args), (sy_call_t *)linux_msgctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 71 = linux_msgctl */
	{ AS(linux_fcntl_args), (sy_call_t *)linux_fcntl, AUE_FCNTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 72 = linux_fcntl */
	{ AS(flock_args), (sy_call_t *)sys_flock, AUE_FLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 73 = flock */
	{ AS(fsync_args), (sy_call_t *)sys_fsync, AUE_FSYNC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 74 = fsync */
	{ AS(linux_fdatasync_args), (sy_call_t *)linux_fdatasync, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 75 = linux_fdatasync */
	{ AS(linux_truncate_args), (sy_call_t *)linux_truncate, AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 76 = linux_truncate */
	{ AS(linux_ftruncate_args), (sy_call_t *)linux_ftruncate, AUE_FTRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 77 = linux_ftruncate */
	{ AS(linux_getdents_args), (sy_call_t *)linux_getdents, AUE_GETDIRENTRIES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 78 = linux_getdents */
	{ AS(linux_getcwd_args), (sy_call_t *)linux_getcwd, AUE_GETCWD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 79 = linux_getcwd */
	{ AS(linux_chdir_args), (sy_call_t *)linux_chdir, AUE_CHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 80 = linux_chdir */
	{ AS(fchdir_args), (sy_call_t *)sys_fchdir, AUE_FCHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 81 = fchdir */
	{ AS(linux_rename_args), (sy_call_t *)linux_rename, AUE_RENAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 82 = linux_rename */
	{ AS(linux_mkdir_args), (sy_call_t *)linux_mkdir, AUE_MKDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 83 = linux_mkdir */
	{ AS(linux_rmdir_args), (sy_call_t *)linux_rmdir, AUE_RMDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 84 = linux_rmdir */
	{ AS(linux_creat_args), (sy_call_t *)linux_creat, AUE_CREAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 85 = linux_creat */
	{ AS(linux_link_args), (sy_call_t *)linux_link, AUE_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 86 = linux_link */
	{ AS(linux_unlink_args), (sy_call_t *)linux_unlink, AUE_UNLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 87 = linux_unlink */
	{ AS(linux_symlink_args), (sy_call_t *)linux_symlink, AUE_SYMLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 88 = linux_symlink */
	{ AS(linux_readlink_args), (sy_call_t *)linux_readlink, AUE_READLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 89 = linux_readlink */
	{ AS(linux_chmod_args), (sy_call_t *)linux_chmod, AUE_CHMOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 90 = linux_chmod */
	{ AS(fchmod_args), (sy_call_t *)sys_fchmod, AUE_FCHMOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 91 = fchmod */
	{ AS(linux_chown_args), (sy_call_t *)linux_chown, AUE_LCHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 92 = linux_chown */
	{ AS(fchown_args), (sy_call_t *)sys_fchown, AUE_FCHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 93 = fchown */
	{ AS(linux_lchown_args), (sy_call_t *)linux_lchown, AUE_LCHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 94 = linux_lchown */
	{ AS(umask_args), (sy_call_t *)sys_umask, AUE_UMASK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 95 = umask */
	{ AS(gettimeofday_args), (sy_call_t *)sys_gettimeofday, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 96 = gettimeofday */
	{ AS(linux_getrlimit_args), (sy_call_t *)linux_getrlimit, AUE_GETRLIMIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 97 = linux_getrlimit */
	{ AS(getrusage_args), (sy_call_t *)sys_getrusage, AUE_GETRUSAGE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 98 = getrusage */
	{ AS(linux_sysinfo_args), (sy_call_t *)linux_sysinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 99 = linux_sysinfo */
	{ AS(linux_times_args), (sy_call_t *)linux_times, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 100 = linux_times */
	{ AS(linux_ptrace_args), (sy_call_t *)linux_ptrace, AUE_PTRACE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 101 = linux_ptrace */
	{ 0, (sy_call_t *)linux_getuid, AUE_GETUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 102 = linux_getuid */
	{ AS(linux_syslog_args), (sy_call_t *)linux_syslog, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 103 = linux_syslog */
	{ 0, (sy_call_t *)linux_getgid, AUE_GETGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 104 = linux_getgid */
	{ AS(setuid_args), (sy_call_t *)sys_setuid, AUE_SETUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 105 = setuid */
	{ AS(setgid_args), (sy_call_t *)sys_setgid, AUE_SETGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 106 = setgid */
	{ 0, (sy_call_t *)sys_geteuid, AUE_GETEUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 107 = geteuid */
	{ 0, (sy_call_t *)sys_getegid, AUE_GETEGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 108 = getegid */
	{ AS(setpgid_args), (sy_call_t *)sys_setpgid, AUE_SETPGRP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 109 = setpgid */
	{ 0, (sy_call_t *)linux_getppid, AUE_GETPPID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 110 = linux_getppid */
	{ 0, (sy_call_t *)sys_getpgrp, AUE_GETPGRP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 111 = getpgrp */
	{ 0, (sy_call_t *)sys_setsid, AUE_SETSID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 112 = setsid */
	{ AS(setreuid_args), (sy_call_t *)sys_setreuid, AUE_SETREUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 113 = setreuid */
	{ AS(setregid_args), (sy_call_t *)sys_setregid, AUE_SETREGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 114 = setregid */
	{ AS(linux_getgroups_args), (sy_call_t *)linux_getgroups, AUE_GETGROUPS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 115 = linux_getgroups */
	{ AS(linux_setgroups_args), (sy_call_t *)linux_setgroups, AUE_SETGROUPS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 116 = linux_setgroups */
	{ AS(setresuid_args), (sy_call_t *)sys_setresuid, AUE_SETRESUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 117 = setresuid */
	{ AS(getresuid_args), (sy_call_t *)sys_getresuid, AUE_GETRESUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 118 = getresuid */
	{ AS(setresgid_args), (sy_call_t *)sys_setresgid, AUE_SETRESGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 119 = setresgid */
	{ AS(getresgid_args), (sy_call_t *)sys_getresgid, AUE_GETRESGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 120 = getresgid */
	{ AS(getpgid_args), (sy_call_t *)sys_getpgid, AUE_GETPGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 121 = getpgid */
	{ AS(linux_setfsuid_args), (sy_call_t *)linux_setfsuid, AUE_SETFSUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 122 = linux_setfsuid */
	{ AS(linux_setfsgid_args), (sy_call_t *)linux_setfsgid, AUE_SETFSGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 123 = linux_setfsgid */
	{ AS(linux_getsid_args), (sy_call_t *)linux_getsid, AUE_GETSID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 124 = linux_getsid */
	{ AS(linux_capget_args), (sy_call_t *)linux_capget, AUE_CAPGET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 125 = linux_capget */
	{ AS(linux_capset_args), (sy_call_t *)linux_capset, AUE_CAPSET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 126 = linux_capset */
	{ AS(linux_rt_sigpending_args), (sy_call_t *)linux_rt_sigpending, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 127 = linux_rt_sigpending */
	{ AS(linux_rt_sigtimedwait_args), (sy_call_t *)linux_rt_sigtimedwait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 128 = linux_rt_sigtimedwait */
	{ AS(linux_rt_sigqueueinfo_args), (sy_call_t *)linux_rt_sigqueueinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 129 = linux_rt_sigqueueinfo */
	{ AS(linux_rt_sigsuspend_args), (sy_call_t *)linux_rt_sigsuspend, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 130 = linux_rt_sigsuspend */
	{ AS(linux_sigaltstack_args), (sy_call_t *)linux_sigaltstack, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 131 = linux_sigaltstack */
	{ AS(linux_utime_args), (sy_call_t *)linux_utime, AUE_UTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 132 = linux_utime */
	{ AS(linux_mknod_args), (sy_call_t *)linux_mknod, AUE_MKNOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 133 = linux_mknod */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 134 = uselib */
	{ AS(linux_personality_args), (sy_call_t *)linux_personality, AUE_PERSONALITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 135 = linux_personality */
	{ AS(linux_ustat_args), (sy_call_t *)linux_ustat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 136 = linux_ustat */
	{ AS(linux_statfs_args), (sy_call_t *)linux_statfs, AUE_STATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 137 = linux_statfs */
	{ AS(linux_fstatfs_args), (sy_call_t *)linux_fstatfs, AUE_FSTATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 138 = linux_fstatfs */
	{ AS(linux_sysfs_args), (sy_call_t *)linux_sysfs, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 139 = linux_sysfs */
	{ AS(linux_getpriority_args), (sy_call_t *)linux_getpriority, AUE_GETPRIORITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 140 = linux_getpriority */
	{ AS(setpriority_args), (sy_call_t *)sys_setpriority, AUE_SETPRIORITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 141 = setpriority */
	{ AS(linux_sched_setparam_args), (sy_call_t *)linux_sched_setparam, AUE_SCHED_SETPARAM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 142 = linux_sched_setparam */
	{ AS(linux_sched_getparam_args), (sy_call_t *)linux_sched_getparam, AUE_SCHED_GETPARAM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 143 = linux_sched_getparam */
	{ AS(linux_sched_setscheduler_args), (sy_call_t *)linux_sched_setscheduler, AUE_SCHED_SETSCHEDULER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 144 = linux_sched_setscheduler */
	{ AS(linux_sched_getscheduler_args), (sy_call_t *)linux_sched_getscheduler, AUE_SCHED_GETSCHEDULER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 145 = linux_sched_getscheduler */
	{ AS(linux_sched_get_priority_max_args), (sy_call_t *)linux_sched_get_priority_max, AUE_SCHED_GET_PRIORITY_MAX, NULL, 0, 0, 0, SY_THR_STATIC },	/* 146 = linux_sched_get_priority_max */
	{ AS(linux_sched_get_priority_min_args), (sy_call_t *)linux_sched_get_priority_min, AUE_SCHED_GET_PRIORITY_MIN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 147 = linux_sched_get_priority_min */
	{ AS(linux_sched_rr_get_interval_args), (sy_call_t *)linux_sched_rr_get_interval, AUE_SCHED_RR_GET_INTERVAL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 148 = linux_sched_rr_get_interval */
	{ AS(mlock_args), (sy_call_t *)sys_mlock, AUE_MLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 149 = mlock */
	{ AS(munlock_args), (sy_call_t *)sys_munlock, AUE_MUNLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 150 = munlock */
	{ AS(mlockall_args), (sy_call_t *)sys_mlockall, AUE_MLOCKALL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 151 = mlockall */
	{ 0, (sy_call_t *)sys_munlockall, AUE_MUNLOCKALL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 152 = munlockall */
	{ 0, (sy_call_t *)linux_vhangup, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 153 = linux_vhangup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 154 = modify_ldt */
	{ 0, (sy_call_t *)linux_pivot_root, AUE_PIVOT_ROOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 155 = linux_pivot_root */
	{ AS(linux_sysctl_args), (sy_call_t *)linux_sysctl, AUE_SYSCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 156 = linux_sysctl */
	{ AS(linux_prctl_args), (sy_call_t *)linux_prctl, AUE_PRCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 157 = linux_prctl */
	{ AS(linux_arch_prctl_args), (sy_call_t *)linux_arch_prctl, AUE_PRCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 158 = linux_arch_prctl */
	{ 0, (sy_call_t *)linux_adjtimex, AUE_ADJTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 159 = linux_adjtimex */
	{ AS(linux_setrlimit_args), (sy_call_t *)linux_setrlimit, AUE_SETRLIMIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 160 = linux_setrlimit */
	{ AS(chroot_args), (sy_call_t *)sys_chroot, AUE_CHROOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 161 = chroot */
	{ 0, (sy_call_t *)sys_sync, AUE_SYNC, NULL, 0, 0, 0, SY_THR_STATIC },		/* 162 = sync */
	{ AS(acct_args), (sy_call_t *)sys_acct, AUE_ACCT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 163 = acct */
	{ AS(settimeofday_args), (sy_call_t *)sys_settimeofday, AUE_SETTIMEOFDAY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 164 = settimeofday */
	{ AS(linux_mount_args), (sy_call_t *)linux_mount, AUE_MOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 165 = linux_mount */
	{ AS(linux_umount_args), (sy_call_t *)linux_umount, AUE_UMOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 166 = linux_umount */
	{ AS(swapon_args), (sy_call_t *)sys_swapon, AUE_SWAPON, NULL, 0, 0, 0, SY_THR_STATIC },	/* 167 = swapon */
	{ 0, (sy_call_t *)linux_swapoff, AUE_SWAPOFF, NULL, 0, 0, 0, SY_THR_STATIC },	/* 168 = linux_swapoff */
	{ AS(linux_reboot_args), (sy_call_t *)linux_reboot, AUE_REBOOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 169 = linux_reboot */
	{ AS(linux_sethostname_args), (sy_call_t *)linux_sethostname, AUE_SYSCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 170 = linux_sethostname */
	{ AS(linux_setdomainname_args), (sy_call_t *)linux_setdomainname, AUE_SYSCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 171 = linux_setdomainname */
	{ AS(linux_iopl_args), (sy_call_t *)linux_iopl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 172 = linux_iopl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 173 = ioperm */
	{ 0, (sy_call_t *)linux_create_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 174 = linux_create_module */
	{ 0, (sy_call_t *)linux_init_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 175 = linux_init_module */
	{ 0, (sy_call_t *)linux_delete_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 176 = linux_delete_module */
	{ 0, (sy_call_t *)linux_get_kernel_syms, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 177 = linux_get_kernel_syms */
	{ 0, (sy_call_t *)linux_query_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 178 = linux_query_module */
	{ 0, (sy_call_t *)linux_quotactl, AUE_QUOTACTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 179 = linux_quotactl */
	{ 0, (sy_call_t *)linux_nfsservctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 180 = linux_nfsservctl */
	{ 0, (sy_call_t *)linux_getpmsg, AUE_GETPMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 181 = linux_getpmsg */
	{ 0, (sy_call_t *)linux_putpmsg, AUE_PUTPMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 182 = linux_putpmsg */
	{ 0, (sy_call_t *)linux_afs_syscall, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 183 = linux_afs_syscall */
	{ 0, (sy_call_t *)linux_tuxcall, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 184 = linux_tuxcall */
	{ 0, (sy_call_t *)linux_security, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 185 = linux_security */
	{ 0, (sy_call_t *)linux_gettid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 186 = linux_gettid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 187 = linux_readahead */
	{ 0, (sy_call_t *)linux_setxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 188 = linux_setxattr */
	{ 0, (sy_call_t *)linux_lsetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 189 = linux_lsetxattr */
	{ 0, (sy_call_t *)linux_fsetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 190 = linux_fsetxattr */
	{ 0, (sy_call_t *)linux_getxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 191 = linux_getxattr */
	{ 0, (sy_call_t *)linux_lgetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 192 = linux_lgetxattr */
	{ 0, (sy_call_t *)linux_fgetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 193 = linux_fgetxattr */
	{ 0, (sy_call_t *)linux_listxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 194 = linux_listxattr */
	{ 0, (sy_call_t *)linux_llistxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 195 = linux_llistxattr */
	{ 0, (sy_call_t *)linux_flistxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 196 = linux_flistxattr */
	{ 0, (sy_call_t *)linux_removexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 197 = linux_removexattr */
	{ 0, (sy_call_t *)linux_lremovexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 198 = linux_lremovexattr */
	{ 0, (sy_call_t *)linux_fremovexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 199 = linux_fremovexattr */
	{ AS(linux_tkill_args), (sy_call_t *)linux_tkill, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 200 = linux_tkill */
	{ AS(linux_time_args), (sy_call_t *)linux_time, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 201 = linux_time */
	{ AS(linux_sys_futex_args), (sy_call_t *)linux_sys_futex, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 202 = linux_sys_futex */
	{ AS(linux_sched_setaffinity_args), (sy_call_t *)linux_sched_setaffinity, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 203 = linux_sched_setaffinity */
	{ AS(linux_sched_getaffinity_args), (sy_call_t *)linux_sched_getaffinity, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 204 = linux_sched_getaffinity */
	{ 0, (sy_call_t *)linux_set_thread_area, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 205 = linux_set_thread_area */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 206 = linux_io_setup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 207 = linux_io_destroy */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 208 = linux_io_getevents */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 209 = inux_io_submit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 210 = linux_io_cancel */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 211 = linux_get_thread_area */
	{ 0, (sy_call_t *)linux_lookup_dcookie, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 212 = linux_lookup_dcookie */
	{ AS(linux_epoll_create_args), (sy_call_t *)linux_epoll_create, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 213 = linux_epoll_create */
	{ 0, (sy_call_t *)linux_epoll_ctl_old, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 214 = linux_epoll_ctl_old */
	{ 0, (sy_call_t *)linux_epoll_wait_old, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 215 = linux_epoll_wait_old */
	{ 0, (sy_call_t *)linux_remap_file_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 216 = linux_remap_file_pages */
	{ AS(linux_getdents64_args), (sy_call_t *)linux_getdents64, AUE_GETDIRENTRIES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 217 = linux_getdents64 */
	{ AS(linux_set_tid_address_args), (sy_call_t *)linux_set_tid_address, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 218 = linux_set_tid_address */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 219 = restart_syscall */
	{ 0, (sy_call_t *)linux_semtimedop, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 220 = linux_semtimedop */
	{ AS(linux_fadvise64_args), (sy_call_t *)linux_fadvise64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 221 = linux_fadvise64 */
	{ AS(linux_timer_create_args), (sy_call_t *)linux_timer_create, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 222 = linux_timer_create */
	{ AS(linux_timer_settime_args), (sy_call_t *)linux_timer_settime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 223 = linux_timer_settime */
	{ AS(linux_timer_gettime_args), (sy_call_t *)linux_timer_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 224 = linux_timer_gettime */
	{ AS(linux_timer_getoverrun_args), (sy_call_t *)linux_timer_getoverrun, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 225 = linux_timer_getoverrun */
	{ AS(linux_timer_delete_args), (sy_call_t *)linux_timer_delete, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 226 = linux_timer_delete */
	{ AS(linux_clock_settime_args), (sy_call_t *)linux_clock_settime, AUE_CLOCK_SETTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 227 = linux_clock_settime */
	{ AS(linux_clock_gettime_args), (sy_call_t *)linux_clock_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 228 = linux_clock_gettime */
	{ AS(linux_clock_getres_args), (sy_call_t *)linux_clock_getres, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 229 = linux_clock_getres */
	{ AS(linux_clock_nanosleep_args), (sy_call_t *)linux_clock_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 230 = linux_clock_nanosleep */
	{ AS(linux_exit_group_args), (sy_call_t *)linux_exit_group, AUE_EXIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 231 = linux_exit_group */
	{ AS(linux_epoll_wait_args), (sy_call_t *)linux_epoll_wait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 232 = linux_epoll_wait */
	{ AS(linux_epoll_ctl_args), (sy_call_t *)linux_epoll_ctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 233 = linux_epoll_ctl */
	{ AS(linux_tgkill_args), (sy_call_t *)linux_tgkill, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 234 = linux_tgkill */
	{ AS(linux_utimes_args), (sy_call_t *)linux_utimes, AUE_UTIMES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 235 = linux_utimes */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 236 = vserver */
	{ 0, (sy_call_t *)linux_mbind, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 237 = linux_mbind */
	{ 0, (sy_call_t *)linux_set_mempolicy, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 238 = linux_set_mempolicy */
	{ 0, (sy_call_t *)linux_get_mempolicy, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 239 = linux_get_mempolicy */
	{ 0, (sy_call_t *)linux_mq_open, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 240 = linux_mq_open */
	{ 0, (sy_call_t *)linux_mq_unlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 241 = linux_mq_unlink */
	{ 0, (sy_call_t *)linux_mq_timedsend, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 242 = linux_mq_timedsend */
	{ 0, (sy_call_t *)linux_mq_timedreceive, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 243 = linux_mq_timedreceive */
	{ 0, (sy_call_t *)linux_mq_notify, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 244 = linux_mq_notify */
	{ 0, (sy_call_t *)linux_mq_getsetattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 245 = linux_mq_getsetattr */
	{ 0, (sy_call_t *)linux_kexec_load, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 246 = linux_kexec_load */
	{ AS(linux_waitid_args), (sy_call_t *)linux_waitid, AUE_WAIT6, NULL, 0, 0, 0, SY_THR_STATIC },	/* 247 = linux_waitid */
	{ 0, (sy_call_t *)linux_add_key, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 248 = linux_add_key */
	{ 0, (sy_call_t *)linux_request_key, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 249 = linux_request_key */
	{ 0, (sy_call_t *)linux_keyctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 250 = linux_keyctl */
	{ 0, (sy_call_t *)linux_ioprio_set, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 251 = linux_ioprio_set */
	{ 0, (sy_call_t *)linux_ioprio_get, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 252 = linux_ioprio_get */
	{ 0, (sy_call_t *)linux_inotify_init, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 253 = linux_inotify_init */
	{ 0, (sy_call_t *)linux_inotify_add_watch, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 254 = linux_inotify_add_watch */
	{ 0, (sy_call_t *)linux_inotify_rm_watch, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 255 = linux_inotify_rm_watch */
	{ 0, (sy_call_t *)linux_migrate_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 256 = linux_migrate_pages */
	{ AS(linux_openat_args), (sy_call_t *)linux_openat, AUE_OPEN_RWTC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 257 = linux_openat */
	{ AS(linux_mkdirat_args), (sy_call_t *)linux_mkdirat, AUE_MKDIRAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 258 = linux_mkdirat */
	{ AS(linux_mknodat_args), (sy_call_t *)linux_mknodat, AUE_MKNODAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 259 = linux_mknodat */
	{ AS(linux_fchownat_args), (sy_call_t *)linux_fchownat, AUE_FCHOWNAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 260 = linux_fchownat */
	{ AS(linux_futimesat_args), (sy_call_t *)linux_futimesat, AUE_FUTIMESAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 261 = linux_futimesat */
	{ AS(linux_newfstatat_args), (sy_call_t *)linux_newfstatat, AUE_FSTATAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 262 = linux_newfstatat */
	{ AS(linux_unlinkat_args), (sy_call_t *)linux_unlinkat, AUE_UNLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 263 = linux_unlinkat */
	{ AS(linux_renameat_args), (sy_call_t *)linux_renameat, AUE_RENAMEAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 264 = linux_renameat */
	{ AS(linux_linkat_args), (sy_call_t *)linux_linkat, AUE_LINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 265 = linux_linkat */
	{ AS(linux_symlinkat_args), (sy_call_t *)linux_symlinkat, AUE_SYMLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 266 = linux_symlinkat */
	{ AS(linux_readlinkat_args), (sy_call_t *)linux_readlinkat, AUE_READLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 267 = linux_readlinkat */
	{ AS(linux_fchmodat_args), (sy_call_t *)linux_fchmodat, AUE_FCHMODAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 268 = linux_fchmodat */
	{ AS(linux_faccessat_args), (sy_call_t *)linux_faccessat, AUE_FACCESSAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 269 = linux_faccessat */
	{ AS(linux_pselect6_args), (sy_call_t *)linux_pselect6, AUE_SELECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 270 = linux_pselect6 */
	{ 0, (sy_call_t *)linux_ppoll, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 271 = linux_ppoll */
	{ 0, (sy_call_t *)linux_unshare, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 272 = linux_unshare */
	{ AS(linux_set_robust_list_args), (sy_call_t *)linux_set_robust_list, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 273 = linux_set_robust_list */
	{ AS(linux_get_robust_list_args), (sy_call_t *)linux_get_robust_list, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 274 = linux_get_robust_list */
	{ 0, (sy_call_t *)linux_splice, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 275 = linux_splice */
	{ 0, (sy_call_t *)linux_tee, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 276 = linux_tee */
	{ 0, (sy_call_t *)linux_sync_file_range, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 277 = linux_sync_file_range */
	{ 0, (sy_call_t *)linux_vmsplice, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 278 = linux_vmsplice */
	{ 0, (sy_call_t *)linux_move_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 279 = linux_move_pages */
	{ 0, (sy_call_t *)linux_utimensat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 280 = linux_utimensat */
	{ AS(linux_epoll_pwait_args), (sy_call_t *)linux_epoll_pwait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 281 = linux_epoll_pwait */
	{ 0, (sy_call_t *)linux_signalfd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 282 = linux_signalfd */
	{ 0, (sy_call_t *)linux_timerfd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 283 = linux_timerfd */
	{ AS(linux_eventfd_args), (sy_call_t *)linux_eventfd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 284 = linux_eventfd */
	{ 0, (sy_call_t *)linux_fallocate, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 285 = linux_fallocate */
	{ 0, (sy_call_t *)linux_timerfd_settime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 286 = linux_timerfd_settime */
	{ 0, (sy_call_t *)linux_timerfd_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 287 = linux_timerfd_gettime */
	{ AS(linux_accept4_args), (sy_call_t *)linux_accept4, AUE_ACCEPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 288 = linux_accept4 */
	{ 0, (sy_call_t *)linux_signalfd4, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 289 = linux_signalfd4 */
	{ AS(linux_eventfd2_args), (sy_call_t *)linux_eventfd2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 290 = linux_eventfd2 */
	{ AS(linux_epoll_create1_args), (sy_call_t *)linux_epoll_create1, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 291 = linux_epoll_create1 */
	{ AS(linux_dup3_args), (sy_call_t *)linux_dup3, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 292 = linux_dup3 */
	{ AS(linux_pipe2_args), (sy_call_t *)linux_pipe2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 293 = linux_pipe2 */
	{ 0, (sy_call_t *)linux_inotify_init1, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 294 = linux_inotify_init1 */
	{ 0, (sy_call_t *)linux_preadv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 295 = linux_preadv */
	{ 0, (sy_call_t *)linux_pwritev, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 296 = linux_pwritev */
	{ 0, (sy_call_t *)linux_rt_tsigqueueinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 297 = linux_rt_tsigqueueinfo */
	{ 0, (sy_call_t *)linux_perf_event_open, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 298 = linux_perf_event_open */
	{ 0, (sy_call_t *)linux_recvmmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 299 = linux_recvmmsg */
	{ 0, (sy_call_t *)linux_fanotify_init, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 300 = linux_fanotify_init */
	{ 0, (sy_call_t *)linux_fanotify_mark, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 301 = linux_fanotify_mark */
	{ AS(linux_prlimit64_args), (sy_call_t *)linux_prlimit64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 302 = linux_prlimit64 */
	{ 0, (sy_call_t *)linux_name_to_handle_at, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 303 = linux_name_to_handle_at */
	{ 0, (sy_call_t *)linux_open_by_handle_at, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 304 = linux_open_by_handle_at */
	{ 0, (sy_call_t *)linux_clock_adjtime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 305 = linux_clock_adjtime */
	{ 0, (sy_call_t *)linux_syncfs, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 306 = linux_syncfs */
	{ 0, (sy_call_t *)linux_sendmmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 307 = linux_sendmmsg */
	{ 0, (sy_call_t *)linux_setns, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 308 = linux_setns */
	{ 0, (sy_call_t *)linux_process_vm_readv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 309 = linux_process_vm_readv */
	{ 0, (sy_call_t *)linux_process_vm_writev, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 310 = linux_process_vm_writev */
	{ 0, (sy_call_t *)linux_kcmp, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 311 = linux_kcmp */
	{ 0, (sy_call_t *)linux_finit_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 312 = linux_finit_module */
};
