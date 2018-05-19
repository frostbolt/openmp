default: report


report:
	python plots.py result
	python plots.py result_trs
	pdflatex -synctex=1 -interaction=nonstopmode report.tex
	mv report.pdf ../report.pdf