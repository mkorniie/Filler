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
	cd resources/ && ./filler_vm -f maps/map01 -p1 players/carli.filler -p2 ../mkorniie.filler
	cd ..

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re do

#########>>>>WIN SCORE (map02) - P1
# abanlin.filler*     		1/5   
# carli.filler*          	3/6
# champely.filler*       	5/5
# grati.filler*          	1/5
# hcao.filler* 				2/5
# superjeannot.filler* 		2/5

#########>>>>WIN SCORE (map02) - P1
# abanlin.filler*     		2/5   
# carli.filler*          	5/5
# champely.filler*       	5/5
# grati.filler*          	3/5
# hcao.filler* 				3/4
# superjeannot.filler* 		3/3

#########>>>>WIN SCORE (map02) - P2
# abanlin.filler*     		/5   
# carli.filler*          	/5
# champely.filler*       	5/5
# grati.filler*          	/5
# hcao.filler* 				/4
# superjeannot.filler* 		1/1

#########>>>>WIN SCORE (map02) - P2  NEW CRITERION
# abanlin.filler*     		5/5   
# carli.filler*          	1/4
# champely.filler*       	5/5
# grati.filler*          	/
# hcao.filler* 				/
# superjeannot.filler* 		/