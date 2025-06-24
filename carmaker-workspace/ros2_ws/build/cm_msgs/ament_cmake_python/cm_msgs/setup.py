from setuptools import find_packages
from setuptools import setup

setup(
    name='cm_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('cm_msgs', 'cm_msgs.*')),
)
