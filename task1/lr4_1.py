import random
import string
import time
import threading

def generate_text(length=1000):
    return ''.join(random.choice(string.ascii_letters + string.digits + string.punctuation + ' ')
                   for _ in range(length))


def create_textfile(filename, text):
    with open(filename, 'w') as file:
        file.write(text)


def create_textfile_in_single_thread(num_files):
    start = time.time()
    for i in range(num_files):
        text = generate_text()
        filename = f'file_{i}.txt'
        create_textfile(filename, text)
    end = time.time()
    return end - start


def create_textfile_in_multiple_threads(num_threads, num_files_per_thread):
    start = time.time()


    def worker(thread_id):
        for i in range(num_files_per_thread):
            text = generate_text()
            filename = f'file_thread_{thread_id}_{i}.txt'
            create_textfile(filename, text)


    threads = []
    for i in range(num_threads):
        thread = threading.Thread(target=worker, args=(i,))
        threads.append(thread)
        thread.start()


    for thread in threads:
        thread.join()


    end = time.time()
    return end - start


if __name__ == "__main__":
    num_files = 15
    num_threads = 5
    num_files_per_thread = num_threads
    time_single_thread = create_textfile_in_single_thread(num_files)
    print(f"Single thread time: {time_single_thread} sec")
    time_multiple_threads = create_textfile_in_multiple_threads(num_threads, num_files_per_thread)
    print(f"{num_threads}`threads time: {time_multiple_threads} sec")