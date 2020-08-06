感觉这道题难的不是算法，是理解题意：

示例参数：
数组1(["CQueue","appendTail","deleteHead","deleteHead"])为函数调用顺序：先入栈后出栈两个元素
数组2([[],[3],[],[]])为参数，逐个调用，即value为:,3,,,起中value限制为1 <= values <= 10000的整数则：有效value只有3
返回值([null,null,3,-1])为数组1对于的输出值，无则为null
逻辑["CQueue","appendTail","deleteHead","deleteHead"]
CQueue：new CQueue() -> null
appendTail：入栈3 -> null
deleteHead：出栈3 -> 3
deleteHead：栈空 -> -1
实现
维护两个栈(数组)；

进栈(stack1)：
队列尾部插入整数(push)
出栈(stack2)：
队列头部删除整数(pop)
若无元素返回-1

var CQueue = function() {
    this.stack1 = []
    this.stack2 = []
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
	this.stack1.push(value)
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
 	if (!this.stack2.length) {
      while (this.stack1.length) {
        this.stack2.push(this.stack1.pop());
      }
    }
    return this.stack2.pop() || -1
};


c++版本

class CQueue {
public:
    stack<int> tail;
    stack<int> head;
    CQueue() {
        
    }
    void appendTail(int value) {
        tail.push(value);
    }
    
    int deleteHead() {
        if(head.empty()){
            if(tail.empty()){
                return -1;
            }
            while(!tail.empty()){
                 head.push(tail.top());
                 tail.pop();
            }
        }
        int result=head.top();
        head.pop();
        return result;       
    }
};