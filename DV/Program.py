import pandas as pd

df = pd.read_excel('Data Cleaning Start.xlsx')


df.drop(columns=['column_name_to_delete'], inplace=True)

# df.rename(columns={'old_column_name': 'new_column_name'}, inplace=True)

df.drop_duplicates(inplace=True)

df['Column1'] = df['Column1'].str.strip()

df.dropna(inplace=True)

