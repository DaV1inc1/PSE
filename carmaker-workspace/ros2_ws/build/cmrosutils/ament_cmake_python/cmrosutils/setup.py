from setuptools import find_packages
from setuptools import setup

setup(
    name='cmrosutils',
    version='1.1.0',
    packages=find_packages(
        include=('cmrosutils', 'cmrosutils.*')),
)
