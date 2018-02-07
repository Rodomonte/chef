# UPLOAD CHEF

from os import chdir
from subprocess import call

chdir('c:/home/code/chef')
call('git add *')
call('git commit -m "Write detected"')
