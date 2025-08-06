SELECT 
    l.book_id, 
    l.title, 
    l.author, 
    l.genre, 
    l.publication_year, 
    COUNT(b.record_id) AS current_borrowers
FROM library_books l
LEFT JOIN borrowing_records b 
    ON l.book_id = b.book_id AND b.return_date IS NULL
GROUP BY 
    l.book_id, l.title, l.author, l.genre, l.publication_year, l.total_copies
HAVING 
    l.total_copies = COUNT(b.record_id)
ORDER BY 
    current_borrowers DESC,
    l.title ASC;
