'''

Runs all the unit tests related to the InterntOfThings

'''

import os;

# setup test directories
SolutionConfiguration = 'Win32'
SolutionPlatform      = 'Debug'
TestFileNameFormat    = '*Test.exe'
TestsDir = os.path.join('..','..',
                        'InternetOfThingNetwork','solutionBin','Test',
                        SolutionConfiguration,SolutionPlatform,
                        TestFileNameFormat)

TestFiles  = os.listdir(TestsDir)

print(TestFiles)
