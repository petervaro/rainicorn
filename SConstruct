## INFO ########################################################################
##                                                                            ##
##                                 rainicorn                                  ##
##                                 =========                                  ##
##                                                                            ##
##          Macros for ANSI escape sequences in a single header file          ##
##                       Version: 0.1.1.025 (20150607)                        ##
##                              File: SConstruct                              ##
##                                                                            ##
##               For more information about the project, visit                ##
##                 <https://github.com/petervaro/rainicorn>.                  ##
##                       Copyright (C) 2015 Peter Varo                        ##
##                                                                            ##
##  This program is free software: you can redistribute it and/or modify it   ##
##   under the terms of the GNU General Public License as published by the    ##
##       Free Software Foundation, either version 3 of the License, or        ##
##                    (at your option) any later version.                     ##
##                                                                            ##
##    This program is distributed in the hope that it will be useful, but     ##
##         WITHOUT ANY WARRANTY; without even the implied warranty of         ##
##            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            ##
##            See the GNU General Public License for more details.            ##
##                                                                            ##
##     You should have received a copy of the GNU General Public License      ##
##     along with this program, most likely a file in the root directory,     ##
##        called 'LICENSE'. If not, see <http://www.gnu.org/licenses>.        ##
##                                                                            ##
######################################################################## INFO ##

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Indicate the beginning of building
print '\n{:#^80}\n'.format(' SCONS BUILD ')

# C Compiler (gcc|clang)
CC = 'clang'

# C Compiler Flags
CCFLAGS = ['v',
           'O3',
           'Wall',
           'Wextra',
           'pedantic',
           'std=c11']

# GCC Specific Compiler Flags
GCCFLAGS = ['fdiagnostics-color=always']

# CLANG Specific Compiler Flags
CLANGFLAGS = ['fcolor-diagnostics',
              'fmacro-backtrace-limit=0']

# Add compiler specific flags
CCFLAGS.extend(GCCFLAGS if CC == 'gcc' else CLANGFLAGS if CC == 'clang' else [])

# C Pre-Processor Path (Include)
CPPPATH = ['.',
           '/usr/include',
           '/usr/local/include']

# Library paths
LIBPATH = ['/usr/lib',
           '/usr/local/lib']


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# MAINTENANCE
maintain_run = Environment().Command(target='maintain',
                                     source=None,
                                     action='python3 maintain.py')


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# TEST

# Create environment
environment = \
    Environment(CC=CC,
                CCFLAGS=['-' + flag for flag in CCFLAGS if flag],
                CPPPATH=CPPPATH,
                LIBPATH=LIBPATH)
# Compile
environment_out = \
    environment.Program(target="test",
                        source=["test.c"])
# Run
environment_run = \
    environment.Command(target="run",
                        source=None,
                        action="./test")
# Dependencies
environment.Depends(environment_out, maintain_run)
environment.Depends(environment_run, environment_out)
# Default target
Default(environment_out)
