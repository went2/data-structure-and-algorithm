# Quadratic sorting algorithms

时间复杂度（worst）： O(n<sup>2</sup>) 的算法

## bubble sort

冒泡排序：两两比较，大的沉底。


## select sort

选择排序：每轮遍历后，将最小的值放到最前面

选择排序的交换动作更少，没执行一轮遍历，才进行一次交换，冒泡是每次比较都可能交换。

## insertion sort

插入排序
	- 将数组分为左右两部分，左边已排序，右边待排序，要完成的工作从右边每次取一个值，插入到左边已排序的相应位置
	- 右边值的数量起始是length - 1，最终为 0， 左边元素数量起始为1，最后为length
	- 插入到相应位置的实现是，不断和左边最末尾的元素比较，比它小则交换

适用将**实时收到的数据**插入已排序数组的情况

在这三种算法中，如果 data set 已经是排序得差不多的情况下，用 bubble sort 和 insertion sort 会比 select sort 更省时间