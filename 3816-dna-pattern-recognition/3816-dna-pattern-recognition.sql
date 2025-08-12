# Write your MySQL query statement below
select *,
case 
    when dna_sequence regexp "^(ATG)" 
        then 1 
        else 0 
    end as "has_start",
case 
    when dna_sequence regexp "((TAA)|(TAG)|(TGA))$" 
        then 1 
        else 0 
    end as "has_stop",
case 
    when dna_sequence regexp "(ATAT)" 
        then 1 
        else 0 
    end as "has_atat",
case 
    when dna_sequence regexp "G{3}" 
        then 1 
        else 0 
    end as "has_ggg"
from samples;