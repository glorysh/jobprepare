1. select
    - int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

2. poll
    - int poll(struct pollfd *fds, nfds_t nfds, int timeout);

3. epoll
    - epoll_create
    - epoll_ctl
    - epoll_wait