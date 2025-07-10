import sqlite3


def get_conn():
    try:
        conn = sqlite3.connect("to_do2.db")
        cursor = conn.cursor()
        return (conn,cursor)
    except Exception as e:
        print(f"error while getting the data base : {e}")
    
def create_task(conn,cursor):
    task_title = input("Please enter task's title: ")
    task_content = input("Please enter task's content")
    try:
        cursor.execute("INSERT into tasks(task_title, task_content) VALUES(?,?)",(task_title, task_content))
        conn.commit()
    except Exception as e: 
        print(f"Error creating task: {e}")

def display_tasks(cursor):
    try:
        cursor.execute("SELECT * FROM tasks")
        tasks = cursor.fetchall()
        print("_________Tasks____________")
        for task_id, task_title,task_content in tasks:
            print(f"{task_id} __ {task_title}__{task_content}")
    
        print("_________End______________")
    except Exception as e :
        print(f"Error while fetching the tasks: {e}")

def delete_tasks(conn,cursor):
    print("_____________Deleting task____________\n \n")
    task_id = int(input("Please enter task id: "))
    try:
        cursor.execute("DELETE from tasks WHERE task_id = ?",(task_id,))
        conn.commit()
        print("Task deleted")
    except Exception as e:
        print(f"Error while deleting tasks : {e}")

def update_task(conn,cursor):
    delete_tasks(conn,cursor)
    create_task(conn,cursor)


def main():
    conn,cursor = get_conn()

    cursor.execute('''CREATE TABLE IF NOT EXISTS tasks(
                    task_id INTEGER PRIMARY KEY AUTOINCREMENT,
                    task_title TEXT,
                    task_content TEXT)''')
    
    print("__________TO_DO_LIST_____________")
    while True:
        user_input = int(input("1/Create, 2/Display, 3/Delete, 4/Update  : "))

        match user_input:
            case 1:
                create_task(conn,cursor)
            case 2:
                display_tasks(cursor)
            case 3:
                delete_tasks(conn,cursor)
            case 4:
                update_task(conn,cursor)
            case 0:
                break
            case _:
                print("please enter a correct number")
    conn.close()

main()
