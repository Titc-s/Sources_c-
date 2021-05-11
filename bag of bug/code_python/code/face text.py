import MySQLdb

#db = MySQLdb.connect("localhost","test","root",charset='utf8')

#cursor  = db.cursor()

#cursor.execute("select version()")  #使用execute方法执行sql语句

#data = cursor.fetchone()  #使用fetchone方法获取数据。

#db.close() #关闭连接

MySQLdb.connect("localhost","test","root",charset='utf8').close()

 