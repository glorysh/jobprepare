1.  定时是指在一段时间之后触发某段代码的机制，可以在这段代码中一次处理所有到期的定时器。定时机制是定时器得以被处理的原动力。Linux提供了三种定时方法：
    - socket选项SO_RCVTIMEO和SO_SNDTIMEO：分别用来设置socket接收数据超时时间和发送给数据超时时间。
    - SIGALRM信号：由alarm和setitimer函数设置的实时闹钟一旦超时，将触发SIGALRM信号。可以利用该信号的信号处理函数来处理定时任务。
    - I/O复用系统调用的超时参数