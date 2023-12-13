#include <QCoreApplication>
#include <QTcpSocket>
#include <QTextCodec>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(qApp->arguments().count() > 1)
    {
        QStringList vstr = qApp->arguments().at(1).split(",");
        QTcpSocket *tcpSocket = new QTcpSocket();
        if(tcpSocket->open(QIODevice::ReadWrite))
        {
            QString strIP = vstr.at(0);//IP地址
            int iPort = vstr.at(1).toUInt();//端口号
            QString strType = vstr.at(2);//消息类型，HEX或STR
            QString strMsg = vstr.at(3);//待发送消息
            QByteArray baMsg;//待发送消息

            tcpSocket->abort();//取消已有的连接
            tcpSocket->connectToHost(strIP, iPort);//连接服务器

            if(tcpSocket->waitForConnected(100))//等待连接成功
            {
                if(strType == "HEX")
                {
                    baMsg = QByteArray::fromHex(strMsg.toLatin1());
                }
                else if(strType == "STR")
                {
                    QTextCodec *codec = QTextCodec::codecForName("GBK");
                    baMsg = codec->fromUnicode(strMsg);
                }

                if(!baMsg.isEmpty())
                {
                    tcpSocket->write(baMsg);
                }

                tcpSocket->close();//关闭连接
            }
        }

    }

    //延时关闭
    QTimer::singleShot(50, [=]{
        qApp->exit(0);
    });

    return a.exec();
}
