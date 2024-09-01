import sys
import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.keys import Keys
import subprocess
import pyperclip
import random

#subprocess.Popen(r'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe --remote-debugging-port=9222 --user-data-dir="C:/chromeCookie"')
options, driver = None, None

def init():
    global options
    global driver
    options = Options()
    # options.add_argument('--headless')  # 화면에 띄우지 않음
    options.add_argument('--no-sandbox')
    options.add_argument('--disable-gpu')
    options.add_argument("--incognito")
    options.add_argument("--window-size=1734,1045")
    options.add_argument('user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.75 Safari/537.36')
    options.add_argument('log-level=3')
    driver = webdriver.Chrome(options=options)

def login(id, password):
    global options
    global driver
    driver.get('https://www.acmicpc.net/login?next=%2F')
    try:
        el_id = driver.find_element(By.NAME,'login_user_id')
        el_pass = driver.find_element(By.NAME,'login_password')
        bt_login = driver.find_element(By.CSS_SELECTOR,'.btn-u.pull-right')
    except:
        return True
    id = pyperclip.copy(id)
    el_id.send_keys(Keys.CONTROL,'v')
    password = pyperclip.copy(password)
    el_pass.send_keys(Keys.CONTROL,'v')
    bt_login.click()
    time.sleep(5)
    try:
        WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.NAME,'login_user_id')))
    except:
        return True
    return False


def submit(problem_id, language, source_code):
    global options
    global driver
    driver.get('https://www.acmicpc.net/submit/'+str(problem_id))

    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.ID, 'language_chosen')))
    driver.execute_script('$("#language_chosen").trigger("mousedown");')

    langs = WebDriverWait(driver, 10).until(EC.presence_of_all_elements_located((By.CSS_SELECTOR, '.chosen-results li')))
    lang_selected = False

    for lang in langs:
        if lang.text.lower() == language.lower():
            lang_selected = True
            lang.click()
            break

    if not lang_selected:
        return False

    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CLASS_NAME, 'CodeMirror-code')))
    CM = driver.find_element(By.CLASS_NAME,'CodeMirror')
    CL = CM.find_element(By.CLASS_NAME,'CodeMirror-line')
    CL.click()
    code = CM.find_element(By.CSS_SELECTOR,'textarea')
    source_code = pyperclip.copy(source_code)
    code.send_keys(Keys.CONTROL,'v')

    driver.find_element(By.ID,'submit_button').click()
    while driver.find_element(By.CLASS_NAME,'result').text.startswith('채점'):
        time.sleep(1)
    # while driver.find_element(By.CLASS_NAME,'result').text.startswith('기다리는 중'):
    #     time.sleep(1)
    if driver.find_element(By.CLASS_NAME,'result').text.startswith('맞았습니다!!'):
        return True
    else:
        return False

# def find_code():
#     for i in range(0,40000):
#         try:
#             file = open(str(i)+'.py').read()
#             pr = submit(i,'Python 3',file)
#             print('Problem : '+str(i)+' submit succeed : '+str(pr))
#             time.sleep(2)
#         except:
#             pass

def do_random_game():
    while True:
        try:
            pid = 10944
            pr = submit(pid,'Text','1')
            print('Problem : '+str(pid)+' submit succeed : '+str(pr))
            if pr:
                break
            print('waiting...')
            time.sleep(random.randint(10, 120))
        except:
            time.sleep(random.randint(5,10))
            pass

init()
while not login('id', 'pw'):
    driver.quit()
    init()
do_random_game()

