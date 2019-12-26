using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;
public static class DataGridViewExtensions
{
    public static string[] CreateRowsArray(this DataGridView sender, string Delimitor = ",")
    {
        return
            (
                from row in sender.Rows.Cast<DataGridViewRow>()
                where !((DataGridViewRow)row).IsNewRow
                let RowItem = string.Join(Delimitor, Array.ConvertAll(((DataGridViewRow)row).Cells.Cast<DataGridViewCell>().ToArray(),
                (DataGridViewCell c) => ((c.Value == null) ? "" : c.Value.ToString())))
                select RowItem
                ).ToArray();
    }
    public static void Export(this string[] sender, string pFileName)
    {
        File.WriteAllLines(pFileName, sender);
    }
}