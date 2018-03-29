NAME = mkorniie.filler
GCC_FLAGS = -Wall -Wextra -Werror
LIB_NAME = libft.a

FILLER_CFILES = ft_filler.c get_next_line.c ft_parse.c ft_getplace.c
FILLER_OFILES = $(FILLER_CFILES:.c=.o)

all: $(NAME)
$(NAME): $(FILLER_OFILES)
	make -C libft/ 
	gcc $(FLAGS) -o $(NAME) $(FILLER_OFILES) -L. -lft
clean:
	rm -f $(FILLER_OFILES) 
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
do: all
	./$(NAME)
doc: all
	cd resources/ && ./filler_vm -f maps/map00 -p1 ../mkorniie.filler -p2 players/champely.filler
	cd ..

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do