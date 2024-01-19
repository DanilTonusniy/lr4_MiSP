import urllib.request
import time
import concurrent.futures

urls = [
    'https://www.pnzgu.ru/',
    'https://moodle.pnzgu.ru/my/',
    'https://lk.pnzgu.ru/portfolio/my' ]


def urlstatus(url):
    with urllib.request.urlopen(url) as u:
        return u.getcode()


start = time.time()
with concurrent.futures.ThreadPoolExecutor() as executor:
    results = executor.map(urlstatus, urls)
for url, status in zip(urls, results):
    print(url, status)
print(time.time() - start)