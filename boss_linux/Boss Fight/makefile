#Makefile v2.18

CC		= g++
CFLAGS	= -Wall -o
PROG	= game
SRC		= Sources/*.cpp
PLAT	= SFML

#When true, will force compilation even if the code hasn't been changed
F_REMAKE= true

#Creates a backup of the code
C_BACKUP = false

#When true, the code will run directly after compilation
RUN_AFTER = true

LIBSFORSFML		= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LIBSFOROPENGL	= -lglut -lGLU

#Conditionals Ahead!!!!
ifeq ($(PLAT),OPENGL)
	LIBS	= $(LIBSFOROPENGL)
else ifeq ($(PLAT),SFML)
	LIBS	= $(LIBSFORSFML)
else
	LIBS	=
endif

all: static1 backup remake $(PROG) run static2 

$(PROG):	$(SRC)
	$(CC) $(CFLAGS) $(PROG) $(SRC) $(LIBS)
clean:
	rm -f $(PROG)

static1:
	@printf "\n################################################################################\n\t\t\t  Compiling and Running Code\n################################################################################\nCommands Executed:\n"
static2:
	@printf "\n################################################################################\n\t\t\t\tTask Complete\n################################################################################\n\t\n"
	
#Another Conditional!!!!
ifeq ($(F_REMAKE),true)
remake:
	@touch $(SRC)
else
remake:

endif

#Another Conditional!!!! x2
ifeq ($(C_BACKUP),true)
backup:
	@mkdir -p ../Backup
	@cp $(SRC) ../Backup
	@cp makefile ../Backup
else
backup:

endif

#Another Conditional!!!! x3
ifeq ($(RUN_AFTER),true)
run:
	./$(PROG)
else
run:
	
endif
