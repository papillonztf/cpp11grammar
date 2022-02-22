#pragma once

class TaskQueue{
public:
    static void AddTask(Task task);

private:
    static queue<Task> m_taskQueue;//由于取头插尾，选用queue适配器
};
queue<Task> TaskQueue::m_taskQueue;
    
