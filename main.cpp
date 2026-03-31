#include <iostream>
#include <vector>

// Set structure of a task (title, completed)

struct Task{
    std::string title;
    bool completed;
};


// Functions-------

// Show Menu - simply prints the menu options to the user, e.g. 1. add task ----- void showMenu()



void showMenu(){
    std::cout << "\n ===== Task Manager =====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Complete\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Quit\n";
    std::cout << "Choose an option: ";
}






// Add Task - adds a task to the vector ---- void addTask(vector<task> & tasks)

void addTask(std::vector<Task> & tasks){

    Task newTask;

    std::cout << "Enter Task Title: ";

    std::cin.ignore();

    std::getline(std::cin, newTask.title);

    newTask.completed = false;

    tasks.push_back(newTask);

    std::cout << "Task added successfully.\n";

}

// View Task - Loops through all the tasks and shows the title and if their completed. void viewTasks(const vector<Task>& tasks)

void viewTasks(const std::vector<Task> & tasks){

    if (tasks.empty()) {
        std::cout << "You have no tasks left.";
        return;
    }

    std::cout << "----Your Tasks----";

    for (int i = 0; i < tasks.size(); i++){
        std::cout << i+1 << ".";

        if (tasks[i].completed){
            std::cout << "[Done] ";
        }else{
            std::cout << "[Not Done] ";
        }

        std::cout << tasks[i].title << "\n";
    }

}

// Mark task as completed - marks a task as completed. void markTaskCompleted(vector<Task>& Tasks)

void markTaskCompleted(std::vector<Task>& tasks){

    if (tasks.empty()){
        std::cout << "You don't have any tasks ";
        return;
    }

    viewTasks(tasks);

    int taskNumber;

    std::cout << "Enter a task number";

    std::cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()){
        std::cout << "Invalid Input";
        return;
    }

    tasks[taskNumber - 1].completed = true;

    std::cout << "Task marked as completed.\n";

}

// Delete Task - shows the list and asks user to select which task to delete. Deletes the task. void deleteTask(vector<Task>& tasks)

void deleteTask(std::vector<Task>& tasks){
    if (tasks.empty()){
        std::cout << "You don't have any tasks";
        return;
    }

    viewTasks(tasks);
    int taskNumber;

    std::cout << "Enter a task number";
    std::cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()){
        std::cout << "Invalid Input";
        return;
    }

    tasks.erase(tasks.begin() + (taskNumber-1));

    std::cout << "Task deleted succesffuly.\n";
}


int main(){
    std::vector<Task> tasks;
    int choice;

    do{
        showMenu();
        std::cin >> choice;

        switch(choice){
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                std::cout << "Goodbye.";
                break;
            default:
                std::cout << "Invalid option. Try again \n";
        }

    }while (choice != 0);

    return 0;
}