package org.easybooks.test.model.vo;
public class UserTable {
	//����
	private Integer id;
	private String username;
	private String password;
	
	//���� id �� get/set ����
	public Integer getId(){
		return this.id;
	}
	public void setId(Integer id){
		this.id=id;
	}
	//���� username �� get/set ����
	public String getUsername(){
		return this.username;
	}
	public void setUsername(String username){
		this.username=username;
	}
	//���� password �� get/set ����
	public String getPassword(){
		return this.password;
	}
	public void setPassword(String password){
		this.password=password;
	}
}