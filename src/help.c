/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:18:33 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/11 17:38:17 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		help_main2(void)
{
	ft_putendl("                                          "
	":::::::::: :::::::::    ::::::::::");
	ft_putendl("                                         "
	":+:        :+:    :+:   :+:");
	ft_putendl("                                        "
	"+:+        +:+    +:+   +:+");
	ft_putendl("                                       "
	":#::+::#   +#+    +:+   :#::+::#");
	ft_putendl("                                      "
	"+#+        +#+    +#+   +#+");
	ft_putendl("                                     "
	"#+#        #+#    #+#   #+#");
	ft_putendl("                                    "
	"###        #########    ###\n\n");
	ft_putwstr(L"                           ~+~+~+~+~+ 1er paramètre "
	": Fichier à ouvrir ~+~+~+~+~\n");
	ft_putwstr(L"       ~+~+~+~+~+ 2ème et 3ème paramètres :"
	" Respectivement largeur et hauteur de la fenêtre ~+~+~+~+~+\n");
	ft_putwstr(L"                       ~+~+~+~+~+ 4ème paramètre"
	" : Couleur pour les segments ~+~+~+~+~+\n");
	ft_putstr("                    ~+~+~+~+~+ Couleurs dispos"
	" : WHITE \033[0;49;35mPINK \033[31mRED \033[34mBLUE"
	" \033[32mGREEN \033[0;49;93mGOLD \033[0m ~+~+~+~+~+\n");
}

void		help_main(void)
{
	help_main2();
	ft_putendl("\n\n      :::    :::     :::     :::     ::: ::::::::::"
"          :::::::::: :::    ::: ::::    :::          ::: ");
	ft_putendl("     :+:    :+:   :+: :+:   :+:     :+: :+:"
"                 :+:        :+:    :+: :+:+:   :+:          :+:  ");
	ft_putendl("    +:+    +:+  +:+   +:+  +:+     +:+ +:+"
"                 +:+        +:+    +:+ :+:+:+  +:+          +:+   ");
	ft_putendl("   +#++:++#++ +#++:++#++: +#+     +:+ +#++:++#            "
":#::+::#   +#+    +:+ +#+ +:+ +#+          +#+    ");
	ft_putendl("  +#+    +#+ +#+     +#+  +#+"
"   +#+  +#+                 +#+        +#+    +#+ +#+  +#+#+#"
"          +#+     ");
	ft_putendl(" #+#    #+# #+#     #+#   #+#+#+#"
"   #+#                 #+#        #+#    #+# #+#   #+#+#                   ");
	ft_putendl("###    ### ###     ###     ###"
"     ##########          ###         ########  ###    ####"
"          ###       ");
}

void		help_fdf(t_all *a)
{
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 100, a->win_y / 2 - 175,
	a->color, "camera sur x et y");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 180, a->win_y / 2 - 140,
	a->color, "R et F pour bouger la camera sur z");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 200, a->win_y / 2 - 105,
	a->color, "WASD pour pivoter la camera sur x et y");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 200, a->win_y / 2 - 70,
	a->color, "ALT G & D pour pivoter la camera sur z");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 150, a->win_y / 2 - 35,
	a->color, "+ et - du keypad pour zoomer");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 190, a->win_y / 2,
	a->color, "Q et E pour modifier le z des points");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 190, a->win_y / 2 + 35,
	a->color, "4 et 6 du keypad pour la rotation de ");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 90, a->win_y / 2 + 70,
	a->color, "la camera sur x");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 190, a->win_y / 2 + 105,
	a->color, "5 et 8 du keypad pour la rotation de ");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 90, a->win_y / 2 + 140,
	a->color, "la camera sur y");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 190, a->win_y / 2 + 175,
	a->color, "H pour quitter le menu de binding des ");
	mlx_string_put(a->mlx, a->win, a->win_x / 2 - 90, a->win_y / 2 + 205,
	a->color, "touches, enjoy !");
}
