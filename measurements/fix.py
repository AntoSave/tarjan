import os

path = os.path.join(os.path.dirname(os.path.realpath(__file__)),"measure/mpi")
os.chdir(path)
folders = [f for f in os.listdir('.')]
for folder in folders:
  os.chdir(os.path.join(path, folder))
  files = [f for f in os.listdir('.')]
  print("FILES:", files)
  for filename in files:
    with open(filename, 'r') as file:
      line = file.readline()
      print(line)
    with open(filename, 'w') as file:
      pass
  