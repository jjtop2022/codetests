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
    print ("everything is OK {}".format(check_disk_usage("/")))

