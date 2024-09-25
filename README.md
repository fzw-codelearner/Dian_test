# 华中科技大学售货机简易代码(Dian团队测试题)

## 项目介绍
1-1项目主要实现:
- 接受摆放货物信息后,输出货物所在通道编号 数量以及单价等信息

1-2项目主要实现:
- 获取所需总价后,不断执行投币操作(只能投1 2 5元)直至达到总价
- 输出找零信息

1-3项目主要实现:
- 摆放货物(同项目1-1)
- 选择货物
- 投币购买(同项目1-2)

2-1项目主要实现:
- 在1-3项目基础上支持多达**五个通道**可以摆放货物

2-2项目主要实现:
- 在2-2基础上实现仅限3次**回退操作**的功能


## 具体实现
仅介绍2-2项目的主要实现方法:
- 以结构体Channel**存储通道信息**.包含整型的单价和数量以及字符的货物名称(以ABCD等字母代替)
- 通过fgets函数获取输入信息,并存储在inp字符串中
- 通过判断特定位置是否为对应的类型,**检测格式**是否正确
- 使用整型ci来判断**回退次数**是否超过三次
- 通过Channel结构的二维数组history来**存储通道的历史信息**,方便回退时对历史数据的读取
- 采用Tihuan函数进行history中通道**历史信息的更新**和回退时**历史信息对当前通道的覆盖**

## 常见错误
格式错误:
- 在摆放和选择货物之后添加了空格
- 在摆放和选择货物中间没有用空格间隔
- 通道编号超过5,单价超过9,货物数量超过了两位数
- 投币不为1 2或者5元

回退问题:
- 次数超过3次
- 还未输入新信息(比如说购买完一次货物之后开始新的选择货物时不能回退,因为没有选择货物)

其他问题程序中均有相应提示.

## 作者
fzw-codelearner