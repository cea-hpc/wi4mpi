# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import sphinx_rtd_theme

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Wi4MPI'
copyright = '2016-2022, CEA - Commissariat à l\'Énerge Atomique et aux Énergies Alternatives'
author = 'Adrien Cotte, Vincent Ducrot, Tony Delforge'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_logo = '../img/logo-full-white.svg'
html_favicon = '../img/logo-square-blue.svg'

html_theme_options = { 'logo_only' : True }
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

html_static_path = ['_static']
