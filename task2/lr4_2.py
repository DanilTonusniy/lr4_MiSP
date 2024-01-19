import random
import string
import time
import multiprocessing

def generate_text(length=1000):
    return ''.join(random.choice(string.ascii_letters + string.digits + string.punctuation + ' ')
                   for _ in range(length))


def create_textfile(filename, text):
    with open(filename, 'w') as file:
        file.write(text)


def create_textfile_in_multiprocesses(num_processes, num_files_per_process):
    start = time.time()


    def worker(process_id):
        for i in range(num_files_per_process):
            text = generate_text()
            filename = f'file_process_{process_id}_{i}.txt'
            create_textfile(filename, text)
            
            
    processes = []
    for i in range(num_processes):
        process = multiprocessing.Process(target=worker, args=(i,))
        processes.append(process)
        process.start()
    for process in processes:
        process.join()
    end = time.time()
    return end - start


if __name__ == "__main__":
    num_files = 15
    num_processes = 5
    num_files_per_process = num_processes
    time_multiprocesses = create_textfile_in_multiprocesses(num_processes, num_files_per_process)
    print(f"{num_processes}` processes time: {time_multiprocesses} sec")