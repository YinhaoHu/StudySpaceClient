# HData模块文档

---

## 模块信息

* 简介：HData是Centhoo Library中的管理Key-value类型存储数据的轻量级模块。为Centhoo Applications系列编写。
* 版本：1.0
* 更新日期：2023年2月5日
* 作者：Henry Hoo

---

## 类描述

### 基础信息 更新函数请查看HData.hpp

* HDataItem是HData数据缓冲区的元素。

* 建议使用.hdat为文件扩展名。

* 基于STL编写
  
  ### HData

* construtor(filename, delimeter):打开文件并且规定数据行中数据元素间的分界符，默认为SPACE

* void load(): 加载文件数据到HData数据缓冲区。

* void save()：保存HData数据缓冲区的数据到文件。

* bool fail(): 返回文件打开状态是否失败。

* int size()： 返回HData数据缓冲区Item的个数。

* int find(x)：查找x在HData数据缓冲区中的下标，如果不在则返回-1。

* HDataItem& access(idx)：访问HData数据缓冲区中下标为idx的元素。

* bool modify(idx, newItem)：修改HData数据缓冲区中下标为idx的元素为newItem。

* bool remove(idx)：删除HData数据缓冲区下标为idx的元素。

* void append(newItem)：添加newItem到HData数据缓冲区中。
  
  ### HDataItem

* toStdString(item)：由item生成std::string

* fromStdString(str)：由std::string类型str生成HDataItem

### HWDataItem & HWData

* 分别与HDataItem 和 HData有相同的接口(除toStdWString 和 fromStdWString外);

---

## 安全问题

* 为保证类的线程安全性，在多线程使用场景中，有必要使用互斥锁。

---

## 编码问题

* HWData的基本数据类型为wchar_t(在Linux和Windows系统上分别是4字节和2字节大小，需要注意), HData的基本数据类型为char。

---

## 示例程序

```
#include"HData.hpp"

int main()
{
    ceh::Data::HData dataFile("file.hdat");
    ceh::Data::HDataItem dataItem("Key", { "Value1","Value2" });
    ceh::Data::HDataItem newDataItem("newKey", { "newValue1","newValue2","newValue3" });

    dataFile.load();//Must when operate.

    dataFile.append(dataItem);
    dataFile.access(0);//You can also use: dataFile[0]
    dataFile.modify(0, newDataItem);//You can also use: dataFile[0] = newDataItem;
    dataFile.remove(0);

    dataFile.save();

    return 0;
}
```
