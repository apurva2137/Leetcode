import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    buyers = customers.merge(orders , how = 'left' , left_on = 'id' , right_on='customerId')

    non_buyers = buyers[buyers['customerId'].isna()]

    return non_buyers[['name']].rename(columns ={'name' : 'Customers'})
    