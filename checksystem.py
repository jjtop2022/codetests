import shutil
import psutil

def check_disk_usage(disk):
    du = shutil.disk_usage(disk)
    free = du.free / du.total * 100
    return free

def check_cpu_usage():
    usage = psutil.cpu_percent(1)
    return usage < 75

if not check_disk_usage("/") > 10 or not check_cpu_usage():
    print("ERROR!")
else:
    print ("everything is OK {0:.2f}".format(check_disk_usage("/")))

class MyTest:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def move(self):
        print("move")
    def draw(self):
        print("draw")

mytest = MyTest(23, 33)
print(mytest.x)
print(mytest.move())
print(mytest.draw())
    
