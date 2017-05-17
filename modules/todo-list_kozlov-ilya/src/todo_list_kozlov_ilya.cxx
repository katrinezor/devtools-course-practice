// Copyright 2017 Kozlov Ilya

#include "include/todo_list_kozlov_ilya.h"
#include <string>

TODOList::TODOTask::TODOTask() {
}

TODOList::TODOTask::TODOTask(const std::string _users_task_name) {
    task_name = _users_task_name;
}

void TODOList::TODOTask::Rename(const std::string _new_task_name) {
    task_name = _new_task_name;
}

void TODOList::TODOTask::SetDone() {
    task_status = DONE_TASK;
}

void TODOList::TODOTask::SetUndone() {
    task_status = UNDONE_TASK;
}

std::string TODOList::TODOTask::GetTaskName() {
    return task_name;
}

TaskStatus TODOList::TODOTask::GetTaskStatus() {
    return task_status;
}

TODOList::TODOList() {
    todo_list_name = "New TODO List";
}

TODOList::TODOList(const std::string _users_todo_list_name) {
    todo_list_name = _users_todo_list_name;
}

void TODOList::NewTask() {
    if (data_list.size() < max_tasks_value) {
        TODOTask new_task;
        data_list.push_back(new_task);
    }
}

void TODOList::NewTask(const std::string _new_task_name) {
    if (data_list.size() < max_tasks_value) {
        TODOTask new_task(_new_task_name);
        data_list.push_back(new_task);
    }
}

void TODOList::DeleteTask(const std::size_t _task_index) {
    if ((_task_index <= data_list.size()) && (_task_index > 0)) {
            data_list.erase(data_list.begin() + _task_index - 1);
    }
}

void TODOList::ClearList() {
    data_list.clear();
}

void TODOList::RenameTask(const std::size_t _task_index,
                          const std::string _new_task_name) {
    if ((_task_index <= data_list.size()) && (_task_index > 0)) {
        data_list[_task_index - 1].Rename(_new_task_name);
    }
}

void TODOList::ShowTODOList() {
    std::cout << "TODO List Name: " << todo_list_name << std::endl;
    std::cout << "Available tasks count: " << max_tasks_value << std::endl;
    std::cout << "Current tasks count: " << data_list.size() << std::endl;
    std::cout << std::endl;
    for (unsigned int i = 0; i < data_list.size(); i++) {
        std::cout << i + 1 << ": " << data_list[i].GetTaskName();
        std::cout << " - " << data_list[i].GetTaskStatus() << std::endl;
    }
}

void TODOList::LimitTasksCount(const std::size_t _new_limit) {
    if ((_new_limit > 0) && (_new_limit < data_list.max_size())) {
        max_tasks_value = _new_limit;
        if (data_list.size() > max_tasks_value) {
            data_list.resize(max_tasks_value);
        }
    }
}

void TODOList::UnlimitTasksCount() {
    max_tasks_value = data_list.max_size();
}

void TODOList::SetTaskDone(const std::size_t _task_index) {
    if (_task_index <= data_list.size()) {
        data_list[_task_index - 1].SetDone();
    }
}

void TODOList::SetTaskUndone(const std::size_t _task_index) {
    if (_task_index <= data_list.size()) {
        data_list[_task_index - 1].SetUndone();
    }
}

void TODOList::ChangeTasksPosition(const std::size_t _current_postiton,
                                   const std::size_t _new_position) {
    if ((_current_postiton < data_list.size())
        && (_new_position < max_tasks_value)
        && (_new_position != _current_postiton)
        && (_new_position > 0)
        && (_current_postiton > 0)) {
        if (_current_postiton < _new_position) {
            std::rotate(data_list.begin() + _current_postiton-1,
                        data_list.begin() + _current_postiton,
                        data_list.begin() + _new_position);
        } else {
                 std::rotate(data_list.begin() + _new_position-1,
                 data_list.begin() + _current_postiton,
                 data_list.begin() + _current_postiton);
                }
    }
}

const std::size_t TODOList::GetMaxTaskValue() {
    return max_tasks_value;
}

const std::size_t TODOList::GetCurrentTasksValue() {
    return data_list.size();
}

std::string TODOList::GetTaskName(const std::size_t _task_index) {
    if (_task_index > data_list.size()) {
        throw "The index is out of range! The function can't return anything";
    }
    return data_list[_task_index - 1].GetTaskName();
}

TaskStatus TODOList::GetTaskStatus(const std::size_t _task_index) {
    if (_task_index > data_list.size()) {
        throw "The index is out of range! The function can't return anything";
    }
    return data_list[_task_index - 1].GetTaskStatus();
}

std::string TODOList::GetTODOListName() {
    return todo_list_name;
}
