1. HTTPS怎么工作的？加密和认证过程了解吗？
    - 加密 + 认证 + 完整性保护 == HTTPS
    - HTTP先和SSL通信，再由SSL和TCP通信   SSL(Secure Sockes Layer) 安全套接字协议
    - 对称加密+非对称加密 + 数字证书 + 数字签名
2. Linux的top命令都可以查看哪些内容？
    -load average, tasks(running, sleeping, stopped, zombie), cpu, Mem, Swap,具体进程信息
3. 泛洪攻击及解决办法：
    - 降低SYN timeout时间，使得主机尽快释放半连接的占用或者采用SYN cookie设置，如果短时间内收到了某个IP的重复SYN请求，我们就认为受到了攻击。我们合理的采用防火墙设置等外部网络也可以进行拦截。