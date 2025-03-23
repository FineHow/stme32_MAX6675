# stme32_MAX6675

通过stm32 ，max6675热电偶传感器，OLED屏幕和蓝牙实现动态实时测温，并可以手机端实时监控温度变化

# **项目整体架构及思路**

**STM32F103ZET6系列单片机，MAX6675K系列热电偶，0.96寸基于IIC的四针OLED屏幕，加上HC-05系列主从一体的蓝牙**

[![](http://116.62.220.150/upload/image-wnnv.png)](http://116.62.220.150/upload/image-wnnv.png)

## **1 工程文件设计**

[![](http://116.62.220.150/upload/image-nfcc.png)](http://116.62.220.150/upload/image-nfcc.png)

图3.工程文件

工程文件主要分为四大部分，分为oled部分，MAX6675部分，串口 SPI，IIC等通讯部分，蓝牙部分。

程序流程主要是通过热电偶检测到了原始数据，上传至STM32,进行换算成摄氏度后，通过串口发送到PC主机上，同时将数据进行字模转换使其在OLED显示屏上显示，将数据同步使用蓝牙发送至手机上。实现三端实时动态数据的显示。[![](http://116.62.220.150/upload/image-zznp.png)](http://116.62.220.150/upload/image-zznp.png)

图4 系统结构


### **OLED显示部分**

**    ** 硬件部分，OLED采用IIC通讯，其中VCC可接3.3V\~5V，SCL接PB6,PB7;但由于我们后续设计可能涉及到的接线冲突，我们这里在软件中将IIC的引脚映射到PB10,PB11中，方便后续拓展。

[![](http://116.62.220.150/upload/image-nwev.png)](http://116.62.220.150/upload/image-nwev.png)

图10 OLED模块

实现将得到的数据显示在OLED屏幕上需要将数据转换STR字符串型，调用字模里的字符显示，其中数字型和英文字符及数字字符可以直接调用头文件，中文字符需要使用字模软件进行转换才可以显示到屏幕上。

需要调用到的OLED头文件，在头文件里设置了我们显示屏的刷新频率，显示模式，坐标的位置设定等。以及我们转换好的字模也放置在此，方便在主程序中直接调用。

[![](http://116.62.220.150/upload/image-esbc.png)](http://116.62.220.150/upload/image-esbc.png)

最终，我们可以在主程序中直接通过OLED\_ShowCHinese将文字输出在显示屏上，也可以将我们转换好的温度数据通过OLED\_ShowChar()，OLED\_ShowString();进行输出

[![](http://116.62.220.150/upload/image-bype.png)](http://116.62.220.150/upload/image-bype.png)

图9 OLED主函数部分

最终我们的显示结果如下图

[![](http://116.62.220.150/upload/image-jppc.png)](http://116.62.220.150/upload/image-jppc.png)

图10 OLED屏幕显示结果

# **3 蓝牙部分**

手机下载e调试，然后直接将蓝牙模块通过串口接入即可。

记得要使用主从一体的蓝牙最好。

# **4. 结果**

[![](http://116.62.220.150/upload/image-avpz.png)](http://116.62.220.150/upload/image-avpz.png)

图10 水温检测实验结果

可以看出水温实时显示在PC端和OLED屏幕上，实验结束。
