@setlocal
@set TMPFIL=D:\UTILS\Sudoku\examples\diabolical.txt
@if NOT EXIST %TMPFIL% (
@echo Can NOT locate %TMPFIL%! *** FIX ME ***
@exit /b 1
)

@set TMPEXE=Release\Sudo-Solver.exe
@if NOT EXIST %TMPEXE% (
@echo Can NOT locate %TMPEXE%! *** FIX ME ***
@exit /b 1
)

%TMPEXE% %TMPFIL% %*
