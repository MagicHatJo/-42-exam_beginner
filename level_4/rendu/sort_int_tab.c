/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:44:38 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 17:44:38 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void swap(int *a, int *b) 
{ 
    int	t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int *arr, int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void quickSort(int *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void	sort_int_tab(int *tab, unsigned int size)
{
	quickSort(tab, 0, size - 1);
}
