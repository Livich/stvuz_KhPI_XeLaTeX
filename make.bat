for %%* in (.) do set CurrentDir=%%~n*
"latexmk.exe" -pdf -silent -pdflatex="xelatex -shell-escape -synctex=1 %CurrentDir%.tex"