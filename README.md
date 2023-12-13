# MacroDeckTCP

Send TCP Msg using Macro Deck 2
使用Macro Deck 2发送TCP消息

**This is not a MacroDeck plugin, it is just a Tcp client based on Qt**
**这不是MacroDeck的插件，只是一个基于Qt的TCP客户端**

不想专门开发一个MacroDeck的插件，所以使用取巧方式发送TCP信息。

具体逻辑就是使用MacroDeck中的Windows Utils的Start applicaton动作，以带参方式打开程序，程序会按照参数中的地址把信息发送至指定TCP服务器。

使用方式如下：
![1.PNG](https://github.com/kongbaiku/MacroDeckTCP/blob/main/README/1.png)

Argument："127.0.0.1,1001,STR,Helloworld"
127.0.0.1：TCP服务器地址。
1001：TCP服务器端口。
STR：代表发送的是字符串消息。
HEX：代表发送的是Hex消息。
Helloworld：消息。
