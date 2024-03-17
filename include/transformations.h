/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:43:23 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/03/04 18:22:52 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

# include "typedefs.h"

void	rotate(float output[4][4], t_trigo_table *table);
void	translate(float output[4][4], t_vec3 *translate);
void	scale(float output[4][4], t_vec3 *scale);
void	isometric_transform(float output[4][4]);
void	cabinet_transform(float output[4][4]);

#endif
