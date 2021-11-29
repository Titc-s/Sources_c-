

# HTML

---

超文本标记语言，是一种用于创建网页的标准标记语言。可以使用HTML建立自己的web网点，HTML运行在浏览器上，由浏览器来解析。

----

![img](https://www.runoob.com/wp-content/uploads/2013/06/02A7DD95-22B4-4FB9-B994-DDB5393F7F03.jpg)

其中 ，\<head>元素包含了文档的元（meta）数据。



---



##### HTML标题

* HTML标题(heading)通过\<h1>-\<h6>标签来定义的。
* 浏览器自动在标题前后添加空行。

```html
<h1>一级标题</h1>
<hr>
<h2>这是一个二级标题</h2>
<h3>我是三级标题</h3>
<!-- 我是小注释捏 -->
```

* \<hr>标签在HTML中创建水平分隔线，和markdown中\```类似,可用于分割内容。
* html文档中，注释写法\<!-- 内容 -->；

##### HTML段落

* HTML段落是通过标签\<p>来定义的。
* 使用\<br>标签在不产生一个新段落的情况下换行。

```html
<p>我是第一个段落。</p>
<p>我是第二个段落。</p>
<p>我是第三个段落<br>我被分尸了</p>
```

##### HTML 链接

* HTML链接是通过标签\<a>来定义的。

```html
<a href="https://www.pornhub.com">这是一个链接</a>
```

其中，href 是 Hypertext Reference 的缩写，是指定超链接目标的URL。

##### HTML图像

* HTML图像是通过标签\<img>来定义的。

```html
<img loading="lazy" src="/image/test.jpg" width="258" height="39" />
```



##### HTML文本格式化

* 演示代码如下：

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>菜鸟教程(runoob.com)</title>
</head>

<body>

<b>这个文本是加粗的</b>

<br />

<strong>这个文本是加粗的</strong>

<br />

<big>这个文本字体放大</big>

<br />

<em>这个文本是斜体的</em>

<br />

<i>这个文本是斜体的</i>

<br />

<small>这个文本是缩小的</small>

<br />

这个文本包含
<sub>下标</sub>

<br />

这个文本包含
<sup>上标</sup>

</body>
</html>
```





---

### HTML 元素

| 开始标签                   | 元素内容     | 结束标签 |
| -------------------------- | ------------ | -------- |
| \<p>                       | 这是一个段落 | \</p>    |
| \<a href = "default.html"> | 这是一个链接 | \</a>    |
| \<br>                      | 换行         |          |

* 结束标签 加个反斜杠。

---

##### HTML 元素语法

* 元素以开始标签起始
* 以结束标签终止
* 元素的内容是开始标签与结束标签之间的内容。
* 某些HTML元素具有空内容
  * 空元素实在开始标签中关闭的
* 空元素在开始标签中进行关闭
* 大多数HTML元素可拥有属性
* 大多数HTML元素可以嵌套
* HTML标签对大小写不敏感，但推荐小写标签 :)

---

### HTML 属性

属性是HTML元素提供的附加信息，

---

* HTML元素可以设置属性
* 属性可以在元素中添加附加信息
* 属性一般描述于开始标签
* 属性总是以名称/值对的形式出现，例:name="value";

HTML链接由\<a>定义，链接的地址在href属性中指定：

```html
<a href="http://www.runoob.com">这是一个链接</a>
```

* target属性可以定义被链接文档在何处显示。
* 

---

属性值应该使用双引号引用。

属性和属性值对大小写不敏感，但推荐小写。

---



属性参考手册：https://www.runoob.com/tags/html-reference.html
