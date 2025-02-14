# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import os
import sphinx
import sphinx_rtd_theme

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Wi4MPI'
copyright = '2016-2022, CEA - Commissariat à l\'Énerge Atomique et aux Énergies Alternatives'
author = 'Adrien Cotte, Vincent Ducrot, Tony Delforge, Kevin Juilly'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_logo = '../img/logo-full-white.svg'
html_favicon = '../img/logo-square-blue.svg'

html_theme_options = { 'logo_only' : True }
# Check Sphinx version
# get_html_theme_path is deprecated after 8.1.3
if sphinx.version_info >= (8, 1, 3):
    html_theme_path = []
else:
    html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

html_static_path = ['_static']

# -- Options for Maths----- --------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#confval-numfig

# Figures, tables and code-blocks are automatically numbered if they have a caption.
numfig = True

WI4MPI_DOC_TODOLIST = bool(os.getenv("WI4MPI_DOC_TODOLIST", False))
extensions = [
    'sphinx.ext.todo',
    'sphinx.ext.ifconfig',
    'sphinx.ext.graphviz',
]

if WI4MPI_DOC_TODOLIST:
    todo_include_todos = True
    todo_link_only = True
else:
    exclude_patterns.append("TODO_list.rst") 


def setup(app):
    app.add_config_value('WI4MPI_DOC_TODOLIST', False, False)
