default: report

report:
	python plots.py
	pdflatex -synctex=1 -interaction=nonstopmode report.tex
	mv report.pdf ../report.pdf
