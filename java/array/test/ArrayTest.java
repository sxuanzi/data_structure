package com.array.test;

import org.junit.Test;

import com.array.Array;
import com.array.GenericArray;
import com.array.Student;

public class ArrayTest {
	
	@Test
	public void arrayTest(){
		Array array = new Array(10);
		array.add(1);
		array.add(2);
		array.add(3);
		array.add(4);
		array.printAll();
		array.insert(1, 9);
		array.printAll();
		array.delete(13);   
		array.printAll();
		
	}
	
	@Test
	public void genericArray(){
		GenericArray<Student> genericArray = new GenericArray<Student>();
		Student student1 = new Student(4,"小环");
		genericArray.add(1, new Student(1,"小黑"));
		genericArray.add(2, new Student(2,"小白"));
		genericArray.add(3, new Student(3,"小蓝"));
		genericArray.add(4, student1);
		System.out.println("比较数组是否相同"+genericArray.contains(student1));
		System.out.println("获取数组的容量："+genericArray.getCapacity());
		System.out.println("获取数组的个数："+genericArray.count());
		genericArray.set(2,new Student(2, "小黑修"));
		System.out.println("获取修改之后的索引值："+genericArray.get(2).toString());
		System.out.print("获取对应元素的下标"+genericArray.find(student1));
		genericArray.add(2, new Student(1,"我是插入的值"));
		System.out.println("删除1下标并返回值"+ genericArray.remove(1));
		System.out.println(genericArray.toString());
	
	}

}
